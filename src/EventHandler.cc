/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "EventHandler.hh"

using namespace Entropy::Mnemosyne;
using namespace std;
using namespace Entropy::Theia::Events;
using namespace Entropy::Mnemosyne::Events;

EventHandler::EventHandler() :
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
	)
{
	_on_event.setEvent([this](const Entropy::Event &e) { this->onEvent(e); });
	_on_event.setUnknown([this](const Entropy::Event &e) { this->onUnknownEvent(e); });
}

EventHandler::~EventHandler() = default;

void EventHandler::onEvent(const Entropy::Event &ev)
{
	_on_event(ev);
}

void EventHandler::onUnknownEvent(const Entropy::Event &ev)
{
	ENTROPY_THROW(UnknownEvent() << EventInfo(ev));
}
