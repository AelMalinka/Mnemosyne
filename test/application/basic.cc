/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Application.hh"
#include "Resources/Json.hh"

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

#		ifndef HAVE_CXX_FS
			EXPECT_THROW(app.addSearchPath("data"), Exception);

			basic = app.get("data/basic.json", Resources::Json());
#		else
			app.addSearchPath("data");

			basic = app.get("basic.json", Resources::Json());
#		endif

		EXPECT_EQ((*basic)["thing"]["value"].asInt(), 10);
	}
}
