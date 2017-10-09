/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include <Entropy/Theia/Application.hh>
#include "Resources/Texture.hh"

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;
using namespace Entropy::Theia;

namespace {
	TEST(ResourceTexture, Create) {
		Application app;

		auto h = Resources::Texture(GL::Texture::Texture2D)("data/pnglogo.png");
	}
}
