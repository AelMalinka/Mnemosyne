dnl Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
dnl Distributed under the terms of the GNU Affero General Public License v3

AC_DEFUN([EX_WITH_CXX_FS], [
	AC_ARG_WITH([cxx-fs],
		[AS_HELP_STRING([--with-cxx-fs], [enable C++17 fs extension])],
		[with_cxx_fs=$withval],
		[with_cxx_fs=check]
	)
	AC_ARG_WITH([cxx-fs-experimental],
		[AS_HELP_STRING([--with-cxx-fs-experimental], [enable C++17 fs extension (experimental)])],
		[with_cxx_fs_exp=$withval],
		[with_cxx_fs_exp=check]
	)

	AS_IF([test "x$with_cxx_fs_exp" != xno -a "x$with_cxx_fs" != xno], [
		AC_PREPROC_IFELSE(
			[AC_LANG_SOURCE([[#ifndef __has_include
				#error "__has_include is rqeuired for this test"
				#endif
				#if !__has_include(<experimental/filesystem>)
				#error "experimental/filesystem not found"
				#endif]])
			],
			[AC_DEFINE_UNQUOTED([HAVE_CXX_FS], [1], [Defined if C++FS support found])
				AC_DEFINE_UNQUOTED([HAVE_CXX_FS_EXPERIMENTAL], [1], [Defined if C++FS support is found in experimental namespacing])
				AC_CHECK_LIB([stdc++fs], main, [AC_SUBST([CXX_FS_LIBS], [-lstdc++fs])])
				with_cxx_fs_exp=yes
			],
			[AS_IF([test "x$with_cxx_fs_exp" = xyes], [AC_MSG_FAILURE([c++fs experimental not found])])
			]
		)
	])
	AS_IF([test "x$with_cxx_fs" != xno -a "x$with_cxx_fs_exp" != xyes], [
		AC_PREPROC_IFELSE(
			[AC_LANG_SOURCE([[#ifndef __has_include
				#error "__has_include is required for this test"
				#endif
				#if !__has_include(<filesystem>)
				#error "filesystem not found"
				#endif]])
			],
			[AC_DEFINE_UNQUOTED([HAVE_CXX_FS], [1], [Defined if C++FS support found])
				AC_CHECK_LIB([stdc++fs], main, [AC_SUBST([CXX_FS_LIBS], [-lstdc++fs])])
			],
			[AS_IF([test "x$with_cxx_fs" = xyes], [AC_MSG_FAILURE([c++fs not found])])
			]
		)
	])
])
