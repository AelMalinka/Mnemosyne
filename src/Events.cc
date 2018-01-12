/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Events.hh"

using namespace Entropy::Mnemosyne::Events;
using namespace Entropy::Mnemosyne;
using namespace std;

ModeChange::ModeChange()
	: Event(Id)
{}
