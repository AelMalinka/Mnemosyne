/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Resources/Png.hh"

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;

namespace {
	TEST(ResourcePng, Basic) {
		auto h = Resources::Png()("data/pnglogo.png");
	}
}
