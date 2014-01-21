#!/bin/sh

# Convert our documentation and scripts to DOS format
find . -type f -regex ".*/\(README\|COPYING\)" -exec mv {} {}.txt \;
find . -type f -regex ".*/\(.*\(\.\)\(txt\|html\|pm\|pl\|html\|tt\|tmpl\|cgi\)\|swishspider\)" -exec unix2dos {} \; 2>&1

# Build the installer executable, assumes makensis is in PATH
makensis src/win32/installer.nsi

