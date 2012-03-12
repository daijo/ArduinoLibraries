#
# Makefile for the HCSR04Ultrasonic library.
#
# $Author: cnobile $
# $Date: 2011-09-17 14:04:07 -0400 (Sat, 17 Sep 2011) $
# $Revision: 34 $
#

# Local directory locations.
PACKAGE_PREFIX	= $(shell pwd)
PACKAGE_DIR	= $(shell echo $${PWD\#\#*/})
TODAY		= $(shell date +"%Y-%m-%d")

# Current version
MAJORVERSION    = 1
MINORVERSION    = 1
PATCHLEVEL      = 1
VERSION         = ${MAJORVERSION}.${MINORVERSION}.${PATCHLEVEL}

DISTNAME        = ${PACKAGE_DIR}-$(VERSION)
SVN_PATH	= /exports/nas-storage/cnobile/repos/svnroot/arduino-svn/HCSR04Ultrasonic

#--------------------------------------------------------------
all	: clobber
	(cd ..; tar -czvf $(DISTNAME).tar.gz --exclude .svn $(PACKAGE_DIR))
	(cd ..; zip -r $(DISTNAME).zip $(PACKAGE_DIR)/* --exclude \*/.svn\*)

svn-tag :
	svn copy svn+ssh://foundation${SVN_PATH}/trunk \
          svn+ssh://foundation${SVN_PATH}/tags/tag-${VERSION}-${TODAY} \
          -m "Tag--release $(VERSION)."

#--------------------------------------------------------------
clean	:
	$(shell $(PACKAGE_PREFIX)/cleanDirs.sh clean)

clobber	: clean
	@(cd ..; rm -rf $(DISTNAME).tar.gz $(DISTNAME).zip)
