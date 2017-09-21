# Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
# Distributed under the terms of the GNU Affero General Public License v3

AC_DEFUN([EX_WITH_JSON], [
	AC_ARG_WITH([json],
		[AS_HELP_STRING([--with-json], [location to look for json-cpp])],
		[with_json=$withval],
		[with_json=check]
	)

	AS_IF([test "x$with_json" != xno], [
		JSON_LIBS=
		JSON_CPPFLAGS=
		JSON_LDFLAGS=

		JSON_CPPFLAGS="-I/usr/include/jsoncpp"

		AS_IF([test "x$with_json" != xcheck -a "x$with_json" != xyes], [
			JSON_CPPFLAGS="-I${with_json}"
			JSON_LDFLAGS="-L${with_json}"
		])

		EX_CHECK_LIBRARY([JSON], [json/json.h], [jsoncpp])
		AM_CONDITIONAL([JSON], [test "x$JSON_LIBS" != x])
	])
])
