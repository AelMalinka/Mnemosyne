/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Application.hh"

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#ifdef HAVE_CXX_FS
#	ifdef HAVE_CXX_FS_EXPERIMENTAL
#		include <experimental/filesystem>
#	else
#		include <filesystem>
#	endif
#endif

using namespace Entropy;
using namespace std;

#if defined(HAVE_CXX_FS) && !defined(HAVE_CXX_FS_EXPERIMENTAL)
	using namespace std::filesystem;
#elif defined(HAVE_CXX_FS) && defined(HAVE_CXX_FS_EXPERIMENTAL)
	using namespace std::experimental::filesystem::v1;
#endif

Mnemosyne::Application::Application() :
	Tethys::Application(),
	Aoede::Application(),
	Theia::Application()
{}

Mnemosyne::Application::Application(const int argc, char *argv[]) :
	Tethys::Application(argc, argv),
	Aoede::Application(argc, argv),
	Theia::Application(argc, argv)
{}

Mnemosyne::Application::~Application() = default;

void Mnemosyne::Application::addSearchPath(const string &path)
{
#	ifndef HAVE_CXX_FS
		ENTROPY_THROW(Exception("Search Paths unsuported"));
#	endif

	_paths.push_front(path);
}

string Mnemosyne::Application::findFullPath(const string &file) const
{
	ENTROPY_LOG(Mnemosyne::Log, Severity::Debug) << "Loading " << file;

#	ifdef HAVE_CXX_FS
		for(auto &i : _paths) {
			path p(i + "/"s + file);
			ENTROPY_LOG(Mnemosyne::Log, Severity::Debug) << "Trying " << i << " at " << p;

			if(exists(p)) {
				return p;
			}
		}
#	endif

	return file;
}
