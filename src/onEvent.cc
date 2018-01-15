/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "onEvent.hh"

using namespace Entropy::Mnemosyne;
using namespace Entropy::Theia::Events;
using namespace Entropy::Mnemosyne::Events;
using namespace std;

void onEvent::operator () (const Entropy::Event &ev)
{
	switch(ev.Id()) {
		case Debug::Id:
			call(dynamic_cast<const Debug &>(ev));
		break;
		case Show::Id:
			call(dynamic_cast<const Show &>(ev));
		break;
		case Hide::Id:
			call(dynamic_cast<const Hide &>(ev));
		break;
		case Close::Id:
			call(dynamic_cast<const Close &>(ev));
		break;
		case Resize::Id:
			call(dynamic_cast<const Resize &>(ev));
		break;
		case Tick::Id:
			call(dynamic_cast<const Tick &>(ev));
		break;
		case Key::Id:
			call(dynamic_cast<const Key &>(ev));
		break;
		case Mouse::Id:
			call(dynamic_cast<const Mouse &>(ev));
		break;
		case ModeChange::Id:
			call(dynamic_cast<const ModeChange &>(ev));
		break;
		default:
			unknown(ev);
	}
}

void onEvent::setEvent(const function<void(const Entropy::Event &)> &v)
{
	_event = v;
}

void onEvent::setUnknown(const function<void(const Entropy::Event &)> &v)
{
	_unknown = v;
}

void onEvent::call(const Entropy::Event &e)
{
	if(_event) {
		_event(e);
	}
}

void onEvent::call(const Theia::Events::Debug &e)
{
	if(_debug) {
		_debug(e);
	}
}

void onEvent::call(const Theia::Events::Show &e)
{
	if(_show) {
		_show(e);
	}
}

void onEvent::call(const Theia::Events::Hide &e)
{
	if(_hide) {
		_hide(e);
	}
}

void onEvent::call(const Theia::Events::Close &e)
{
	if(_close) {
		_close(e);
	}
}

void onEvent::call(const Theia::Events::Resize &e)
{
	if(_resize) {
		_resize(e);
	}
}

void onEvent::call(const Theia::Events::Tick &e)
{
	if(_tick) {
		_tick(e);
	}
}

void onEvent::call(const Theia::Events::Key &e)
{
	if(_key) {
		_key(e);
	}
}

void onEvent::call(const Theia::Events::Mouse &e)
{
	if(_mouse) {
		_mouse(e);
	}
}

void onEvent::call(const Events::ModeChange &e)
{
	if(_mode) {
		_mode(e);
	}
}

void onEvent::unknown(const Entropy::Event &e)
{
	if(_unknown) {
		_unknown(e);
	} else {
		ENTROPY_THROW(UnknownEvent() << EventInfo(e));
	}
}

void onEvent::assigns()
{}

void onEvent::assign(const onEvent &o)
{
	if(o._event) _event = o._event;
	if(o._unknown) _unknown = o._unknown;
	if(o._debug) _debug = o._debug;
	if(o._show) _show = o._show;
	if(o._hide) _hide = o._hide;
	if(o._close) _close = o._close;
	if(o._resize) _resize = o._resize;
	if(o._tick) _tick = o._tick;
	if(o._key) _key = o._key;
	if(o._mouse) _mouse = o._mouse;
	if(o._mode) _mode = o._mode;
}

void onEvent::assign(const function<void(const Debug &)> &v)
{
	_debug = v;
}

void onEvent::assign(const function<void(const Show &)> &v)
{
	_show = v;
}

void onEvent::assign(const function<void(const Hide &)> &v)
{
	_hide = v;
}

void onEvent::assign(const function<void(const Close &)> &v)
{
	_close = v;
}

void onEvent::assign(const function<void(const Resize &)> &v)
{
	_resize = v;
}

void onEvent::assign(const function<void(const Tick &)> &v)
{
	_tick = v;
}

void onEvent::assign(const function<void(const Key &)> &v)
{
	_key = v;
}

void onEvent::assign(const function<void(const Mouse &)> &v)
{
	_mouse = v;
}

void onEvent::assign(const function<void(const ModeChange &)> &v)
{
	_mode = v;
}
