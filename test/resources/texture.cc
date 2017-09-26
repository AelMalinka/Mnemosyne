/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Resources/Texture.hh"

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;
using namespace Entropy::Theia;

namespace {
	TEST(ResourceTexture, Create) {
		auto h = Resources::Texture(GL::Texture::Texture2D)("data/pnglogo.png");
	}
}
