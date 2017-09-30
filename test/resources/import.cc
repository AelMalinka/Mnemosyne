/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Resources/Import.hh"
#include "Interface.hh"

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;
using namespace Entropy::Mnemosyne::Test;

namespace {
	TEST(ResourceImport, Basic) {
		auto h = Resources::Import<Interface>()("data/module.so");

		EXPECT_EQ(h->Name(), "Module"s);
		EXPECT_EQ(h->Value(), 11ul);
	}
}
