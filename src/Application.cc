/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Application.hh"

using namespace Entropy;

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
