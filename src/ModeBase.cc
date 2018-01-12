/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "ModeBase.hh"

using namespace Entropy::Mnemosyne;
using namespace std;

using Entropy::DefaultedList;
using Entropy::Theia::Scene;

ModeBase::ModeBase(Application &app)
	: _app(app)
{
	setScene(addScene());
}

ModeBase::~ModeBase() = default;

void ModeBase::makeCurrent()
{
	// 2018-01-10 AMR NOTE: update drawables that might be on multiple Scenes
	// 2018-01-12 AMR TODO: test this actually works, decide if desirable
	_current->getCamera().RunCallbacks();
	_app.Windows()->Scenes().setDefault(_current);
}

DefaultedList<Scene>::iterator ModeBase::addScene()
{
	// 2018-01-12 AMR TODO: handle multiple windows and/or window switches?
	auto i = _app.Windows()->addScene();
	_scenes.push_back(i);

	return i;
}

void ModeBase::setScene(const DefaultedList<Scene>::iterator &i)
{
	_current = i;
}

Scene &ModeBase::Current()
{
	return *_current;
}

const Scene &ModeBase::Current() const
{
	return *_current;
}

DefaultedList<Scene>::iterator ModeBase::getIterator() const
{
	return _current;
}
