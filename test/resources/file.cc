/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Resources/File.hh"

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;

namespace {
	TEST(ResourceFile, Basic) {
		auto h = Resources::File()("data/text");

		EXPECT_FALSE(h->bad());
		EXPECT_FALSE(h->fail());

		string content;
		while(!h->eof() && !h->bad() && !h->fail()) {
			string l;
			getline(*h, l);

			if(l != "")
				content += l + "\n"s;
		}

		EXPECT_EQ(content, "This is a test file\nWith multiple lines\nand some #$%^#$&#*!#@$%& garbage\n"s);
	}
}
