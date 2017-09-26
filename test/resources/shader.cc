/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <gtest/gtest.h>
#include "Resources/Shader.hh"
#include <Entropy/Theia/Window.hh>

using namespace std;
using namespace testing;
using namespace Entropy::Mnemosyne;
using namespace Entropy::Theia;

namespace {
	TEST(ResourceShader, Vertex) {
		Window win("Test Window (hidden)"s, 640, 360);
		auto h = Resources::Shader()("data/shader.vert");
	}
	TEST(ResourceShader, Fragment) {
		Window win("Test Window (hidden)"s, 640, 360);
		auto h = Resources::Shader()("data/shader.frag");
	}
}
