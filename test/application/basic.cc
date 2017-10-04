/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Application.hh"
#include "Resources/Json.hh"
#include "Resources/File.hh"

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;

namespace {
	TEST(Application, Create) {
		Application app;
	}

	TEST(Application, Get) {
		Application app;
		Handle<Json::Value> basic;
		Handle<fstream> file;

#		ifndef HAVE_CXX_FS
			EXPECT_THROW(app.addSearchPath("data"), Exception);

			basic = app.load("data/basic", Resources::Json());
			file = app.load("data/basic.json", Resources::File());
#		else
			app.addSearchPath("data");

			basic = app.load("basic", Resources::Json());
			file = app.load("basic.json", Resources::File());
#		endif

		EXPECT_EQ((*basic)["thing"]["value"].asInt(), 10);
		EXPECT_FALSE(file->fail());
	}
}
