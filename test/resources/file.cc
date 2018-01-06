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

	TEST(ResourceFile, WriteRead) {
		auto h = Resources::File()("data/text");

		EXPECT_FALSE(h->bad());
		EXPECT_FALSE(h->fail());

		(*h) << "Hello File!" << endl;

		EXPECT_FALSE(h->bad());
		EXPECT_FALSE(h->fail());

		Resources::File()("data/text", h);

		auto f = Resources::File()("data/text");

		EXPECT_FALSE(f->bad());
		EXPECT_FALSE(f->fail());

		string content;
		while(!f->eof() && !f->bad() && !f->fail()) {
			string l;
			getline(*f, l);
			if(l != "")
				content += l + "\n"s;
		}

		EXPECT_EQ(content, "Hello File!\nst file\nWith multiple lines\nand some #$%^#$&#*!#@$%& garbage\n"s);
	}
}
