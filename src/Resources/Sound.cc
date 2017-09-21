/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Sound.hh"

using namespace Entropy::Mnemosyne::Resources;
using namespace Entropy::Mnemosyne;
using namespace Entropy;
using namespace std;

Sound::Sound(const bool Repeat)
	: _repeat(Repeat)
{}

Handle<Aoede::Sound> Sound::operator () (const string &path)
{
	return Handle<Aoede::Sound>(make_shared<Aoede::Sound>(path, _repeat));
}
