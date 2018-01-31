/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Handle.hh"

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;

namespace {
	TEST(Handle, Create) {
		struct T {};

		Handle<T> a(make_shared<T>());
		Handle<T> b(a);
		Handle<T> c(move(b));

		EXPECT_NE(a.get(), nullptr);
		EXPECT_EQ(b.get(), nullptr);
		EXPECT_NE(c.get(), nullptr);
	}

	TEST(Handle, Access) {
		struct T {
			int a;
			string b;
			float c;
		};

		Handle<T> a(make_shared<T>());

		a.get()->a = 10;
		(*a).b = "Hello World!";
		a->c = 1.5;

		EXPECT_EQ(a->a, 10);
		EXPECT_EQ(a->b, "Hello World!"s);
		EXPECT_EQ(a->c, 1.5);
	}
}
