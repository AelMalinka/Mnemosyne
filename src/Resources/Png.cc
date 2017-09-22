/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Png.hh"

using namespace Entropy::Mnemosyne::Resources;
using namespace Entropy::Mnemosyne;
using namespace Entropy;
using namespace std;

Handle<PNG> Png::operator () (const string &path)
{
	ENTROPY_LOG(Log, Severity::Info) << "Loading Png: " << path;

	return Handle<PNG>(make_shared<PNG>(path));
}
