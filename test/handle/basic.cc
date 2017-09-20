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
		struct t {};

		Handle<t> a(make_shared<t>());
		Handle<t> b(a);
		Handle<t> c(move(b));
	}
}
