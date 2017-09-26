# Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
# Distributed under the terms of the GNU Affero General Public License v3

ACLOCAL_AMFLAGS = -Im4
AM_CPPFLAGS = -I$(srcdir)/src

mainheadersdir = $(includedir)/Entropy/Mnemosyne
mainheaders_HEADERS = \
	src/Application.hh \
	src/Application.impl.hh \
	src/Exception.hh \
	src/Handle.hh \
	src/Handle.impl.hh

resourceheadersdir = $(mainheadersdir)/Resources
resourceheaders_HEADERS = \
	src/Resources/Exception.hh \
	src/Resources/File.hh \
	src/Resources/Png.hh \
	src/Resources/Shader.hh \
	src/Resources/Sound.hh \
	src/Resources/Texture.hh

lib_LTLIBRARIES = libmnemosyne.la

libmnemosyne_la_SOURCES = \
	src/Application.cc \
	src/Logger.cc \
	src/Resources/File.cc \
	src/Resources/Png.cc \
	src/Resources/Shader.cc \
	src/Resources/Sound.cc \
	src/Resources/Texture.cc
libmnemosyne_la_LDFLAGS = -version-info 0

check_PROGRAMS =
noinst_DATA = \
	data/basic.json \
	data/pnglogo.png \
	data/shader.frag \
	data/shader.vert \
	data/sound.oga

all-local:
	test -d data || $(LN_S) $(top_srcdir)/data $(builddir)/data

if JSON
resourceheaders_HEADERS += \
	src/Resources/Json.hh

libmnemosyne_la_SOURCES += \
	src/Resources/Json.cc
endif

if GTEST
check_PROGRAMS += \
	application-basic \
	handle-basic \
	resource-file \
	resource-png \
	resource-shader \
	resource-sound \
	resource-texture

gtestLDADD = $(LIBS) $(GTEST_LIBS) -lgtest_main libmnemosyne.la

application_basic_SOURCES = test/application/basic.cc
application_basic_LDADD = $(gtestLDADD)

handle_basic_SOURCES = test/handle/basic.cc
handle_basic_LDADD = $(gtestLDADD)

resource_file_SOURCES = test/resources/file.cc
resource_file_LDADD = $(gtestLDADD)

resource_png_SOURCES = test/resources/png.cc
resource_png_LDADD = $(gtestLDADD)

resource_shader_SOURCES = test/resources/shader.cc
resource_shader_LDADD = $(gtestLDADD)

resource_sound_SOURCES = test/resources/sound.cc
resource_sound_LDADD = $(gtestLDADD)

resource_texture_SOURCES = test/resources/texture.cc
resource_texture_LDADD = $(gtestLDADD)

if JSON
check_PROGRAMS += \
	resource-json

resource_json_SOURCES = test/resources/json.cc
resource_json_LDADD = $(gtestLDADD)
endif
endif

TESTSUITE = $(srcdir)/test/testsuite

TESTSUITE_FILES = \
	test/application.at \
	test/handle.at \
	test/resources.at

EXTRA_DIST = $(TESTSUITE_FILES) \
	$(srcdir)/test/testsuite.at \
	$(srcdir)/package.m4 \
	$(TESTSUITE) \
	$(srcdir)/test/atlocal.in

$(srcdir)/package.m4: $(top_srcdir)/configure.ac
	:; {\
		echo '# Signature of the current package. (auto-generated)' && \
		echo 'm4_define([AT_PACKAGE_NAME],' && \
		echo '  [$(PACKAGE_NAME)])' && \
		echo 'm4_define([AT_PACKAGE_TARNAME],' && \
		echo '  [$(PACKAGE_TARNAME)])' && \
		echo 'm4_define([AT_PACKAGE_VERSION],' && \
		echo '  [$(PACKAGE_VERSION)])' && \
		echo 'm4_define([AT_PACKAGE_STRING],' && \
		echo '  [$(PACKAGE_STRING)])' && \
		echo 'm4_define([AT_PACKAGE_BUGREPORT],' && \
		echo '  [$(PACKAGE_BUGREPORT)])'; \
		echo 'm4_define([AT_PACKAGE_URL],' && \
		echo '  [$(PACKAGE_URL)])'; \
	} >'$(srcdir)/package.m4'

check-local: test/atconfig atlocal $(TESTSUITE) $(check_PROGRAMS)
	$(SHELL) '$(TESTSUITE)' AUTOTEST_PATH='$(shell pwd)' $(TESTSUITEFLAGS)

clean-local:
	test ! -f '$(TESTSUITE)' || \
		$(SHELL) '$(TESTSUITE)' --clean

AUTOM4TE = $(SHELL) $(srcdir)/build-aux/missing --run autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest
$(TESTSUITE): $(srcdir)/test/testsuite.at $(TESTSUITE_FILES) $(srcdir)/package.m4
	$(AUTOTEST) -I '$(srcdir)/test' -I $(srcdir) -o $@.tmp $@.at
	mv $@.tmp $@
