/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-develompent.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <cstdlib>

#include <Entropy/Mnemosyne/Application.hh>

using namespace std;
using namespace Entropy;
using namespace Entropy::Mnemosyne;

class Application :
	public Entropy::Mnemosyne::Application
{
	protected:
		void onEvent(const Event &);
};

int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		::Application app;
		app();

		return EXIT_SUCCESS;
	}
	catch (exception &e)
	{
		MessageBox(nullptr, e.what(), "Error!", MB_ICONEXCLAMATION | MB_OK);
		return EXIT_FAILURE;
	}
}

void ::Application::onEvent(const Event &ev)
{
	if (ev.Id() == Theia::Events::Key::Id) {
		const Theia::Events::Key &k = dynamic_cast<const Theia::Events::Key &>(ev);

		if (k.Action() == GLFW_PRESS && k.Code() == GLFW_KEY_ESCAPE) {
			Windows()->Close();
		}
	}
}