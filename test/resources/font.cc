/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Resources/Font.hh"

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;

namespace {
	TEST(ResourceFont, Basic) {
		auto h = Resources::Font()("data/NotoSansUI-Regular.ttf");

		EXPECT_NE((*h)['a'].Advance(), 0);
		EXPECT_NE((*h)['a'].Size().x, 0);
		EXPECT_NE((*h)['a'].Size().y, 0);
		EXPECT_NE((*h)['a'].Bearing().x, 0);
		EXPECT_NE((*h)['a'].Bearing().y, 0);
	}
}
