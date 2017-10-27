/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Shader.hh"
#include <fstream>

using namespace Entropy::Mnemosyne::Resources;
using namespace Entropy::Mnemosyne;
using namespace Entropy::Theia;
using namespace Entropy;
using namespace std;

Handle<GL::Shader> Shader::operator () (const string &path)
{
	GL::Shader::Type t = GL::Shader::Compute;

	if(path.rfind(".") != string::npos) {
		if(path.substr(path.rfind(".")) == ".vert"s) {
			t = GL::Shader::Vertex;
		} else if(path.substr(path.rfind(".")) == ".frag"s) {
			t = GL::Shader::Fragment;
		} else if(path.substr(path.rfind(".")) == ".geom"s) {
			t = GL::Shader::Geometry;
		} else if(path.substr(path.rfind(".")) == ".comp"s) {
			t = GL::Shader::Compute;
		} else {
			ENTROPY_THROW(Exception("Unkown Shader Type") <<
				ResourcePath(path)
			);
		}
	} else {
		ENTROPY_THROW(Exception("Unkown Shader Type") <<
			ResourcePath(path)
		);
	}

	ENTROPY_LOG(Log, Severity::Info) << "Loading Shader: " << path;

	fstream file(path, ios_base::in);
	string code;

	if(file.bad() || file.fail())
		ENTROPY_THROW(Exception("Failed to load shader") <<
			ResourcePath(path)
		);

	while(!file.eof()) {
		string line;
		getline(file, line);

		code += line + "\n";
	}

	return Handle<GL::Shader>(make_shared<GL::Shader>(t, code));
}
