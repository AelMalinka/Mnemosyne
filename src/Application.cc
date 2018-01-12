/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Application.hh"
#include <Entropy/String.hh>

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

#include "Events.hh"

using namespace Entropy::Mnemosyne;
using namespace std;

namespace Tethys = Entropy::Tethys;
namespace Aoede = Entropy::Aoede;
namespace Theia = Entropy::Theia;

using Entropy::Severity;
using Entropy::PolymorphicList;

#if defined(HAVE_CXX_FS) && !defined(HAVE_CXX_FS_EXPERIMENTAL)
	using namespace std::filesystem;
#elif defined(HAVE_CXX_FS) && defined(HAVE_CXX_FS_EXPERIMENTAL)
	using namespace std::experimental::filesystem::v1;
#endif

Application::Application() :
	Tethys::Application(),
	Aoede::Application(),
	Theia::Application(),
	_paths(),
	_modes(),
	_current(_modes.end())
{}

Application::Application(const int argc, char *argv[]) :
	Tethys::Application(argc, argv),
	Aoede::Application(argc, argv),
	Theia::Application(argc, argv),
	_paths(),
	_modes(),
	_current(_modes.end())
{}

Application::~Application() = default;

void Application::operator () ()
{
	if(_current == _modes.end())
		ENTROPY_THROW(NoMode());

	Theia::Application::operator () ();
}

void Application::setMode(const PolymorphicList<ModeBase>::iterator &i)
{
	_current = i;
	_current->makeCurrent();

	Events::ModeChange ev;
	onEvent(ev);
}

PolymorphicList<ModeBase>::iterator Application::addMode(const shared_ptr<ModeBase> &mode)
{
	_modes.push_back(mode);
	return --_modes.end();
}

void Application::onEvent(const Entropy::Event &ev)
{
	_current->onEvent(ev);
}

void Application::addSearchPath(const string &path)
{
#	ifndef HAVE_CXX_FS
		ENTROPY_THROW(Exception("Search Paths unsuported"));
#	endif

	_paths.push_front(path);
}

string Application::findFullPath(const string &file) const
{
	ENTROPY_LOG(Log, Severity::Debug) << "Loading " << file;

#	ifdef HAVE_CXX_FS
		for(auto &i : _paths) {
			path p(i + "/"s + file);
			ENTROPY_LOG(Log, Severity::Debug) << "Trying " << i << " at " << p;

			if(exists(p)) {
				// 2017-10-10 AMR HACK: Windows requires casting path from a wstring to a string
				return string_cast(static_cast<path::string_type>(p));
			}
		}
#	endif

	return file;
}

void Application::createPath(const string &dir) const
{
#	ifdef HAVE_CXX_FS
		ENTROPY_LOG(Log, Severity::Debug) << "Create Directory " << dir;

		path p(dir);
		create_directories(p.parent_path());
#	endif
}

PolymorphicList<ModeBase>::iterator Application::begin()
{
	return _modes.begin();
}

PolymorphicList<ModeBase>::iterator Application::end()
{
	return _modes.end();
}
