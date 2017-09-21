/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Json.hh"
#include <fstream>

using namespace Entropy::Mnemosyne;
using namespace Entropy;
using namespace Json;
using namespace std;

Handle<Value> Resources::Json::operator () (const string &path)
{
	Handle<Value> ret = Handle<Value>(make_shared<Value>());
	fstream file(path, ios_base::in);
	string errors;
	CharReaderBuilder builder;

	if(!parseFromStream(builder, file, ret.get(), &errors))
		ENTROPY_THROW(JsonError(errors));

	return ret;
}
