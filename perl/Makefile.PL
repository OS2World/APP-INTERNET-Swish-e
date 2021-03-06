#!/usr/bin/perl -w

use strict;
use ExtUtils::MakeMaker;
use Config;         # for path separator
use File::Spec;     # for catpath
use File::Basename; # for locating swish-e binary based on location of swish-config

# $Id: Makefile.PL,v 1.16 2004/11/18 21:26:19 whmoseley Exp $

#----------------------------------------------------------------------------------
# Default settings

my %make_maker_opts = (
    NAME            => 'SWISH::API',
    VERSION_FROM    => 'API.pm',
    AUTHOR          => 'Bill Moseley',
    ABSTRACT        => 'Perl interface to the swish-e search library',

    # Set LIBS and INC from swish-confg

    NORECURS        => 1,          # keep it from recursing into subdirectories
    DIR             => [],
    XSPROTOARG      => '-noprototypes',
    PREREQ_PM       => {
        'File::Spec'    => '0.8',
    },
    test          => {
        TESTS         => 't/*.t',
    },
    clean           => {
        FILES            => join( ' ', qw(
            t/index.swish-e
            t/index.swish-e.prop
        )),
    },
);


my $SWISH_BINARY = 'swish-e';
my $SWISH_CONFIG = 'swish-config';
my $MIN_VERSION  = '2.4.3';


my @valid_params = qw/ SWISHBINDIR SWISHHELP SWISHIGNOREVER SWISHSKIPTEST /;




my $help = <<EOF;

SWISH::API build script.

The swish-config program is required to set libraries and include paths.
If swish-config is not in your PATH then use SWISHBINDIR

Makefile.PL options:

    SWISHBINDIR     = full path to swish-e bin directory
    SWISHIGNOREVER  = don't test swish-e version
    SWISHHELP       = print this message
    SWISHSKIPTEST   = create dummy tests for make test.  Don't use...

Can be either environment variables or passed on command line like:

    perl Makefile.PL SWISHBINDIR=/usr/local/bin

EOF

$SIG{__DIE__} = sub {
    print STDERR "\n  ** ERROR: ", @_;
    print STDERR "  Run perl Makefile.PL SWISHHELP for options\n\n";
    exit 1;
};

#----------------------------------------------------------------------------------

# Grab any options passed in on the command line.
# Swish variables get placed in $ENV.

my %config = load_command_line( @valid_params );

if ( exists $ENV{SWISHHELP} ) {
    print $help;
    exit 0;
}


# Grab output from swish-config -- this is required;

my $swish_config_path = find_swish_config( $SWISH_CONFIG );
my %swish_config = read_swish_config( $swish_config_path );

$config{$_} ||= $swish_config{$_} for qw/ LIBS INC /;


test_version( $swish_config{VERSION}, $MIN_VERSION )
    or die "Swish version $swish_config{VERSION} is older than required version $MIN_VERSION\n";



# Create test index -- needed for make test


unless ( exists $ENV{SWISHSKIPTEST} ) {

    my $swish_binary = File::Spec->catdir( dirname( $swish_config_path), $SWISH_BINARY );
    create_index( $swish_binary );

} else {
    $config{test}{TESTS} = 't/dummy.t';
}




WriteMakefile( %make_maker_opts, %config );


#----------------------------------------------------------------------------------
# Test the swish-e version
#----------------------------------------------------------------------------------
sub test_version {
    my %versions;
    my %split_vers;

    return 1 if exists $ENV{SWISHIGNOREVER};

    my @tags = qw/ running_swish_version  required_version /;
    my @versions = qw/ major minor release /;

    @versions{@tags} = @_;


    for ( @tags ) {
        die "Failed to find version for $_\n" unless $versions{$_};
        die "Failed to parse version ($versions{$_}) for $_\n"
            unless $versions{$_} =~ /(\d+)\.(\d+)\.(\d+)/;

        @{$split_vers{$_}}{@versions} = ( $1, $2, $3 );
    }

    for ( @versions ) {
        return 1 if $split_vers{running_swish_version}{$_} > $split_vers{required_version}{$_};
        return 0 if $split_vers{running_swish_version}{$_} < $split_vers{required_version}{$_};
    }
    return 1;  # same version.
}



#----------------------------------------------------------------------------------
# Reads swish-config and returns hash of values
#----------------------------------------------------------------------------------
sub find_swish_config {
    my $prog = shift;

    my $binary = find_program( $prog );

    if ( $ENV{SWISHBINDIR} ) {

        die "SWISHBINDIR [$ENV{SWISHBINDIR}] is not a directory\n"
            unless -d $ENV{SWISHBINDIR};

        my $p = find_program( $prog, $ENV{SWISHBINDIR} );
        die "Failed to find [$prog] in directory $ENV{SWISHBINDIR}: $!" unless $p;

        print "Using config program [$p], but also noticed you have $binary available in \$PATH\n"
            if $binary;

        $binary = $p;
    }


    die "Failed to find [$prog] in PATH\n" unless $binary;

    print "Using swish-config found at [$binary]\n";
    return $binary;
}

#----------------------------------------------------------------------------------
# Reads swish-config and returns hash of values
#----------------------------------------------------------------------------------
sub read_swish_config {
    my $binary = shift;

    my %config;
    $config{VERSION} = backtick( "$binary --version" );
    $config{LIBS}    = backtick( "$binary --libs" );
    $config{INC}     = backtick( "$binary --cflags" );

    return %config;
}


#----------------------------------------------------------------------------------
# Sub to fetch parameters form command line.
# Sets $ENV for SWISH options, otherwise returns them
#----------------------------------------------------------------------------------

sub load_command_line {
    my %valid = map { $_, 1 } @_;

    my %config;
    while( $_ = shift @ARGV ) {
        if ( $_ eq 'SWISHHELP' ) {
            $ENV{SWISHHELP} = 'y';
            last;
        }

        my ( $param, $value ) = split /=/, $_, 2;

        if ( $param =~ /^SWISH/ ) {
            die "Invalid option '$param'\n" unless $valid{$param};
            $ENV{$param} = $value || '';
        } else {
            $config{$param} = $value || '';
        }
    }

    return %config;
}



#----------------------------------------------------------------------------------
# Find a program in either $PATH or path/directory passed in.
#----------------------------------------------------------------------------------
sub find_program {
    my ( $name, $search_path ) = @_;

    $search_path ||= $ENV{PATH} || '';

     for my $dir ( split /$Config{path_sep}/, $search_path ) {
        my $path = File::Spec->catfile( $dir, $name );

        for my $extension ( '', '.exe' ) {
            my $file = $path . $extension;
            return $file  if -x $file && !-d _;
        }
    }
    return;
}


#----------------------------------------------------------------------------------
# Run a program with backtics, checking for errors
#----------------------------------------------------------------------------------

sub backtick {
    my ( $command ) = @_;

    my $output = `$command`;

    my $status = $? == 0
                ? ''
                : $? == -1
                    ? "Failed to execute: $!"
                    : $? & 127
                        ? sprintf("Child died with signal %d, %s corefile", ($? & 127),  ($? & 128) ? 'with' : 'without' )
                        : sprintf("chiled exited with value %d", $? >> 8);

    die "Failed to run program [$command]: $status\n" if $status;

    chomp $output;
    return $output;
}



sub create_index {
    my ($swish) = @_;

    die "Failed to find swish-e binary [$swish]: $!\n" unless -e $swish;
    die "Cannot execute swish-e binary [$swish]: $!\n" unless -x $swish;

    my $index = 't/index.swish-e';
    my $conf = 't/test.conf';


    unlink $index if -e $index;

    my @command = ( $swish,  '-c', $conf, '-f', $index, '-v','0' );


    print "Creating index...'@command'\n\n";

    system(@command);

    die "Failed to create index file '$index'" unless -r $index;
}
