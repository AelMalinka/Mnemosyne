/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Events.hh"

using namespace Entropy::Mnemosyne::Events;
using namespace Entropy::Mnemosyne;
using namespace std;

ModeChange::ModeChange(Application &app, Mode &mode)
	: Event(Id), _app(app), _mode(mode)
{}

Application &ModeChange::getApplication() const
{
	return _app;
}

Mode &ModeChange::getMode() const
{
	return _mode;
}
