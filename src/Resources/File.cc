/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "File.hh"

using namespace Entropy::Mnemosyne::Resources;
using namespace Entropy::Mnemosyne;
using namespace std;

Handle<fstream> File::operator () (const string &path)
{
	return Handle<fstream>(make_shared<fstream>(path, ios_base::in));
}
