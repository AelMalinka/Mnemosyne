/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "ModeBase.hh"

using namespace Entropy::Mnemosyne;
using namespace std;
using namespace Entropy::Theia::Events;
using namespace Entropy::Mnemosyne::Events;

using Entropy::DefaultedList;
using Entropy::Theia::Scene;

ModeBase::ModeBase(Application &app) :
	_app(app),
	_on_event(
		[this](const Debug &e) { this->onEvent(e); },
		[this](const Show &e) { this->onEvent(e); },
		[this](const Hide &e) { this->onEvent(e); },
		[this](const Close &e) { this->onEvent(e); },
		[this](const Resize &e) { this->onEvent(e); },
		[this](const Tick &e) { this->onEvent(e); },
		[this](const Key &e) { this->onEvent(e); },
		[this](const Mouse &e) { this->onEvent(e); },
		[this](const ModeChange &e) { this->onEvent(e); }
	),
	_scenes(),
	_current()
{
	_on_event.setEvent([this](const Entropy::Event &e) { this->onEvent(e); });
	_on_event.setUnknown([this](const Entropy::Event &e) { this->onUnknownEvent(e); });

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

using namespace Entropy::Mnemosyne::Events;
using namespace Entropy::Theia::Events;

void ModeBase::onEvent(const Entropy::Event &ev)
{
	_on_event(ev);
}

void ModeBase::onUnknownEvent(const Entropy::Event &ev)
{
	ENTROPY_THROW(UnknownEvent() << EventInfo(ev));
}
