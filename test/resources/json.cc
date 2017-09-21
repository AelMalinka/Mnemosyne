/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Resources/Json.hh"

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;


namespace {
	TEST(ResourceJson, Basic) {
		auto j = Resources::Json()("data/basic.json");

		EXPECT_EQ((*j)["thing"]["value"].asInt(), 10);
		EXPECT_EQ((*j)["thing"]["name"].asString(), "asdf"s);
	}
}
