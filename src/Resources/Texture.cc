/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Texture.hh"

using namespace Entropy::Mnemosyne::Resources;
using namespace Entropy::Mnemosyne;
using namespace Entropy::Theia;
using namespace Entropy;
using namespace std;

Texture::Texture(const GL::Texture::Type &t)
	: _type(t)
{}

Handle<GL::Texture> Texture::operator () (const string &path)
{
	ENTROPY_LOG(Log, Severity::Info) << "Loading Texture: " << path;

	return Handle<GL::Texture>(make_shared<GL::Texture>(_type, path));
}
