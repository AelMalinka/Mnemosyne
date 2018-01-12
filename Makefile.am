# Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
# Distributed under the terms of the GNU Affero General Public License v3

ACLOCAL_AMFLAGS = -Im4
AM_CPPFLAGS = -I$(srcdir)/src

mainheadersdir = $(includedir)/Entropy/Mnemosyne
mainheaders_HEADERS = \
	src/Application.hh \
	src/Application.impl.hh \
	src/Event.hh \
	src/Events.hh \
	src/Exception.hh \
	src/Handle.hh \
	src/Handle.impl.hh \
	src/Mode.hh \
	src/Mode.impl.hh \
	src/ModeBase.hh

resourceheadersdir = $(mainheadersdir)/Resources
resourceheaders_HEADERS = \
	src/Resources/Exception.hh \
	src/Resources/File.hh \
	src/Resources/Font.hh \
	src/Resources/Png.hh \
	src/Resources/Shader.hh \
	src/Resources/Sound.hh \
	src/Resources/Texture.hh

lib_LTLIBRARIES = libmnemosyne.la

libmnemosyne_la_SOURCES = \
	src/Resources/File.cc \
	src/Resources/Font.cc \
	src/Resources/Png.cc \
	src/Resources/Shader.cc \
	src/Resources/Sound.cc \
	src/Resources/Texture.cc \
	src/Application.cc \
	src/Event.cc \
	src/Events.cc \
	src/Logger.cc \
	src/ModeBase.cc
libmnemosyne_la_LDFLAGS = -version-info 0

check_PROGRAMS = \
	hand-basic

noinst_DATA = \
	data/basic.json \
	data/pnglogo.png \
	data/shader.frag \
	data/shader.vert \
	data/sound.oga

all-local:
	test -d data || $(LN_S) $(top_srcdir)/data $(builddir)/data

hand_basic_SOURCES = test/hand/basic.cc
hand_basic_LDADD = libmnemosyne.la

if JSON
resourceheaders_HEADERS += \
	src/Resources/Json.hh

libmnemosyne_la_SOURCES += \
	src/Resources/Json.cc
endif

module.so: $(srcdir)/test/module/Module.cc $(srcdir)/test/module/Interface.hh $(srcdir)/src/Exception.hh
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(AM_CPPFLAGS) $(LDFLAGS) $(LIBS) -shared -fPIC -o $@ $(srcdir)/test/module/Module.cc

if GTEST
check_PROGRAMS += \
	application-basic \
	handle-basic \
	resource-file \
	resource-font \
	resource-import \
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

resource_font_SOURCES = test/resources/font.cc
resource_font_LDADD = $(gtestLDADD)

resource_import_SOURCES = test/resources/import.cc
resource_import_CPPFLAGS = $(AM_CPPFLAGS) -I$(top_srcdir)/test/module
resource_import_LDADD = $(gtestLDADD)
resource_import_DEPENDENCIES = module.so

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
	$(RM) module.so

AUTOM4TE = $(SHELL) $(srcdir)/build-aux/missing --run autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest
$(TESTSUITE): $(srcdir)/test/testsuite.at $(TESTSUITE_FILES) $(srcdir)/package.m4
	$(AUTOTEST) -I '$(srcdir)/test' -I $(srcdir) -o $@.tmp $@.at
	mv $@.tmp $@
