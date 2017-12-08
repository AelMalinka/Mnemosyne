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

#define TEST_BEGIN try {
#define TEST_END } catch(exception &e) { FAIL() << e << endl; }

namespace {
	TEST(ResourceImport, Basic) {
		TEST_BEGIN
			auto i = Resources::Import<Interface>();
			auto h = i("module"s + i.Extension());

			EXPECT_EQ(h->Name(), "Module"s);
			EXPECT_EQ(h->Value(), 11ul);
		TEST_END
	}
}
