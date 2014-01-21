%define	name	swish-e
%define	version	2.4.3
%define release 4

# SWISH::API definitions
%define filelist %{_tmppath}/%{name}-%{version}/%{name}-%{version}-filelist
%define NVR %{name}-%{version}-%{release}
%define maketest 0

Summary:        SWISH-E - Simple Web Indexing System for Humans - Enhanced
Name:           %{name}
Version:        %{version}
Release:        %{release}
License:        GPL
Group:          Networking/Other
Source:         http://swish-e.org/Download/%{name}-%{version}.tar.gz
URL:            http://swish-e.org/
BuildRoot:      %{_tmppath}/%name-root
Packager:       David L Norris <dave@webaugur.com>
Icon:           swish-e.xpm
Vendor:         SWISH-E Team <http://swish-e.org/>
Provides:       %{name}
Obsoletes:      %{name}-doc
Obsoletes:	swish
Requires:       libxml2, pcre, zlib
BuildRequires:	libxml2-devel, pcre-devel, zlib-devel
Prefix:         /usr

%description
Swish-e is Simple Web Indexing System for Humans - Enhanced

Swish-e can quickly and easily index directories of files or remote 
web sites and search the generated indexes.

Swish-e is extremely fast in both indexing and searching, highly
configurable, and can be seamlessly integrated with existing web sites
to maintain a consistent design. Swish-e can index web pages, but can
just as easily index text files, mailing list archives, or data stored
in a relational database.

%package        perl
Summary:        SWISH-E - PERL Scripts and Modules
Group:          Networking/Other
Provides:       %{name}-perl
Requires:       %{name} = %{version}
Requires:       %{name}-perl-api = %{version}

%description    perl
PERL SWISH-E language bindings and scripts.


%package	perl-api
summary:	SWISH::API - Perl interface to the Swish-e C Library
License:	Artistic
Group:		Applications/CPAN
Provides:	%{name}-perl-api
Provides:	perl-SWISH-API = 0.01
Requires:	%{name} = %{version}

%description	perl-api
SWISH::API provides a Perl interface to the Swish-e search engine.
SWISH::API allows embedding the swish-e search code into your application
avoiding the need to fork to run the swish-e binary and to keep an index file
open when running multiple queries.  This results in increased search performance.


%package	devel
Summary:	SWISH-E - Static libraries and header files.
Group:		Networking/Other
Obsoletes:	swish-devel
Provides:       %{name}-devel
Requires:	%{name} = %{version}

%description	devel
Libraries and header files required for compiling applications based on the SWISH-E API.


%prep
%setup -q

%build
%configure --with-pcre=/usr --with-libxml2=/usr --with-zlib=/usr
make

# Make SWISH::API
pushd perl
grep -rsl '^#!.*perl' . |
grep -v '.bak$' |xargs --no-run-if-empty \
%__perl -MExtUtils::MakeMaker -e 'MY->fixin(@ARGV)'

CFLAGS="$RPM_OPT_FLAGS" SWISHBIN="%{_builddir}/%{name}-%{version}/src/swish-e" %{__perl} Makefile.PL `%{__perl} -MExtUtils::MakeMaker -e ' print qq|PREFIX=%{buildroot}%{_prefix}| if \$ExtUtils::MakeMaker::VERSION =~ /5\.9[1-6]|6\.0[0-5]/ '` 

%{__make} PREFIX=%{buildroot}%{_prefix} LIB='%{_libdir}' LIBS='-L%{_libdir} -L%{buildroot}/src/.libs -lswish-e -lz' 'LDFLAGS=-L%{_libdir} -L%{_builddir}/%{name}-%{version}/src/.libs' 'CCFLAGS=-I%{_builddir}/%{name}-%{version}/src' 'LDDLFLAGS=-shared -L%{_builddir}/%{name}-%{version}/src/.libs/ -lswish-e'

%if %maketest
%{__make} test
%endif
popd

%install
%{__make} DESTDIR=$RPM_BUILD_ROOT prefix=%{prefix} sysconfdir=%{sysconfdir} install

# Install SWISH::API
pushd perl
%{makeinstall} `%{__perl} -MExtUtils::MakeMaker -e ' print \$ExtUtils::MakeMaker::VERSION <= 6.05 ? qq|PREFIX=%{buildroot}%{_prefix}| : qq|DESTDIR=%{buildroot}| '`

[ -x /usr/lib/rpm/brp-compress ] && /usr/lib/rpm/brp-compress

# SuSE Linux
if [ -e /etc/SuSE-release -o -e /etc/UnitedLinux-release ]
then
    %{__mkdir_p} %{buildroot}/var/adm/perl-modules
    %{__cat} `find %{buildroot} -name "perllocal.pod"`  \
        | %{__sed} -e s+%{buildroot}++g                 \
        > %{buildroot}/var/adm/perl-modules/%{name}
fi

# remove special files
find %{buildroot} -name "perllocal.pod" \
    -o -name ".packlist"                \
    -o -name "*.bs"                     \
    |xargs -i rm -f {}

# fix permissions
find %{buildroot} | xargs -i chmod u+w {}

# no empty directories
find %{buildroot}%{_prefix}             \
    -type d -depth                      \
    -exec rmdir {} \; 2>/dev/null

# build list of installed SWISH::API files
%{__perl} -le '
use strict;
use File::Find;
use File::Spec;
use Config qw(%Config);

my $buildroot = "%{buildroot}";
my $sitearch = File::Spec->catdir( $buildroot , $Config{installsitearch} );
my @sitearch;

find( sub{ 
        push(@sitearch, $File::Find::name =~ /\Q$buildroot\E(.+)$/);
    }, $sitearch );

$" = "\n";
print <<EOF;
@sitearch
EOF
' > %{filelist}

[ -z %filelist ] && {
    echo "ERROR: empty files listing"
    exit -1
    } 
popd
# end install SWISH::API

%post	-p /sbin/ldconfig
%postun -p /sbin/ldconfig

%clean
[ "${RPM_BUILD_ROOT}" != "/" ] && [ -d ${RPM_BUILD_ROOT} ] && rm -rf ${RPM_BUILD_ROOT};

%files
%defattr(-, root, root)
%{_bindir}/swish-e
%{_libdir}/*.so.*
%{_mandir}/man[^3]/*
%{_datadir}/doc/swish-e/*

%files perl
%defattr(-, root, root)
%{_bindir}/swish-filter-test
%{_libdir}/swish-e/*
%{_datadir}/swish-e/*

%files perl-api -f %filelist
%defattr(-,root,root)
%doc perl/Changes perl/README
%{_mandir}/man3/SWISH::API.3pm*

%files devel
%defattr(-, root, root)
#%{_mandir}/man3/*.3*
%{_includedir}/*.h
%{_libdir}/*.la
%{_libdir}/*.a
%{_libdir}/*.so

%changelog
* Sun Nov 07 2004 David L Norris <dave@webaugur.com> 2.5.2-4
- Simplify File::Find script.  Merge HTML docs with swish-e package.
* Sun Nov 07 2004 David L Norris <dave@webaugur.com> 2.5.2-3
- Fix dependencies so SWISH::API requires the correct version of SWISH-E.
* Sun Nov 07 2004 David L Norris <dave@webaugur.com> 2.5.2-2
- Incorporate File::Find script written by Peter Karman <karman@cray.com>
* Sat Nov 06 2004 David L Norris <dave@webaugur.com> 2.5.2-1
- Fix SWISH::API build so it compiles without libswish-e being installed.
* Sat Oct 23 2004 David L Norris <dave@webaugur.com> 2.5.2-0
- Add SWISH::API support. Based roughly on spec from Bernhard Weisshuhn <bkw@weisshuhn.de>.
* Sun Jul 11 2004 David L Norris <dave@webaugur.com> 2.5.1
- Made spec a little more generic.
* Fri Oct 24 2003 David L Norris <dave@webaugur.com> 2.4.0-pr4-0
- Added new files and moved extra documentation and examples to a separate package.
* Mon Jun 30 2003 David L Norris <dave@webaugur.com> 2.4.0-pr1-1cefha
- Modified spec file to minimize dependences on CEFHA.org server.
* Thu Jun 19 2003 David L Norris <dave@webaugur.com> 2.4.0-pr1
- Updated RPM spec to provide recently added files
* Sun Apr 20 2003 David L Norris <dave@webaugur.com> 2.3.5
- Updated RPM to provide the SWISH-E helper scripts.
* Fri Mar 28 2003 David L Norris <dave@webaugur.com> 2.3.5
- Updated RPM for the new libtool-based 2.3.5 build system.
* Wed Dec 04 2002 David L Norris <dave@webaugur.com> 2.3-dev04
- Created RPM spec file
