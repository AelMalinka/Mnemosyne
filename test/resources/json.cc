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

	TEST(ResourceJson, Write) {
		auto j = Resources::Json()("data/basic.json");

		EXPECT_EQ((*j)["thing"]["value"].asInt(), 10);
		EXPECT_EQ((*j)["thing"]["name"].asString(), "asdf"s);

		(*j)["thing"]["value"] = 11;

		Resources::Json()("data/basic.json", j);

		auto h = Resources::Json()("data/basic.json");

		EXPECT_EQ((*h)["thing"]["value"].asInt(), 11);
		EXPECT_EQ((*h)["thing"]["name"].asString(), "asdf"s);
	}
}
