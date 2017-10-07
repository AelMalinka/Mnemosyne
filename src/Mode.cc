/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Mode.hh"

using namespace Entropy::Mnemosyne;
using namespace std;

using Entropy::DefaultedList;
using Entropy::Theia::Scene;

Mode::Mode(Application &a)
	: _app(a)
{
	setScene(addScene());
}

Mode::~Mode() = default;

void Mode::makeCurrent()
{
	_app.Windows()->Scenes().setDefault(_current);
}

DefaultedList<Scene>::iterator Mode::addScene()
{
	auto i = _app.Windows()->addScene();
	_scenes.push_back(i);

	return i;
}

void Mode::setScene(const DefaultedList<Scene>::iterator &i)
{
	_current = i;
}

DefaultedList<Scene> &Mode::Scenes()
{
	return _app.Windows()->Scenes();
}

const DefaultedList<Scene> &Mode::Scenes() const
{
	return _app.Windows()->Scenes();
}

Scene &Mode::Current()
{
	return *_current;
}

const Scene &Mode::Current() const
{
	return *_current;
}

DefaultedList<Scene>::iterator Mode::getIterator() const
{
	return _current;
}

Application &Mode::App()
{
	return _app;
}

const Application &Mode::App() const
{
	return _app;
}
