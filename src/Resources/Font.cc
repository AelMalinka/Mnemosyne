/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Font.hh"

using namespace Entropy::Theia::UI;
using namespace Entropy::Mnemosyne;
using namespace Entropy;
using namespace std;

Resources::Font::Font(const size_t count, const FT_UInt height, const FT_Long slot, const FT_UInt width)
	: _count(count), _height(height), _slot(slot), _width(width)
{}

Handle<FT::Font> Resources::Font::operator () (const string &path)
{
	ENTROPY_LOG(Log, Severity::Info) << "Loading Font: " << path;
	return Handle<FT::Font>(make_shared<FT::Font>(path, _count, _height, _slot, _width));
}
