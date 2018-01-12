/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include <cstdlib>
#include <iostream>
#include "Application.hh"
#include "Resources/Shader.hh"
#include <Entropy/SharedData.hh>
#include <Entropy/Theia/Object.hh>
#include <Entropy/Theia/Events.hh>
#include <Entropy/Theia/GL/Program.hh>
#include <Entropy/Theia/GL/Array.hh>

using namespace std;
using namespace Entropy::Log;
using namespace Entropy::Mnemosyne;
using namespace Entropy::Theia::GL;

using Entropy::SharedData;
using Entropy::Theia::Object;
using Entropy::Theia::Camera;
using Entropy::Theia::Screen;

namespace detail {
	struct object {
		object(Application &);
		Program program;
		Array array;
	};
}

Logger AppLog("Application");

class MyObject :
	private SharedData<::detail::object>,
	public Object
{
	public:
		MyObject(Application &);
	private:
		void Draw();
		void UpdateModel();
		void UpdateCamera(const Camera &);
		void UpdateScreen(const Screen &);
};

class MyApp :
	public Application
{
	public:
		MyApp();
};

class MyMode :
	public Mode<MyApp>
{
	public:
		MyMode(MyApp &);
	private:
		void onEvent(const Entropy::Event &);
};

#ifdef _WIN32
	int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#else
	int main()
#endif
{
	try
	{
		MyApp app;
		app();

		return EXIT_SUCCESS;
	}
	catch(exception &e)
	{
#		ifdef _WIN32
			MessageBox(nullptr, e.what(), "Error!", MB_ICONEXCLAMATION | MB_OK);
#		else
			cerr << e << endl;	
#		endif
		return EXIT_FAILURE;
	}
}

void MyMode::onEvent(const Entropy::Event &ev)
{
	using namespace Entropy::Theia::Events;

	if(ev.Id() == Key::Id) {
		const Key &k = dynamic_cast<const Key &>(ev);

		if(k.Action() == GLFW_PRESS && k.Code() == GLFW_KEY_ESCAPE) {
			App().Windows()->Close();
		}
	}
}

::detail::object::object(Application &app)
	: program(), array()
{
	ENTROPY_LOG(AppLog, Severity::Debug) << "MyObject: Started static initialization";
	auto v = app.load("shader.vert", Resources::Shader());
	auto f = app.load("shader.frag", Resources::Shader());

	vector<float> vertices = {
		-1.0, 1.0, 0.0,
		1.0, 1.0, 0.0,
		-1.0, -1.0, 0.0,
		1.0, -1.0, 0.0,
	};

	program.Attach(*v);
	program.Attach(*f);
	program.Link();

	Buffer buf(Buffer::Vertex);
	buf.Data(vertices, Buffer::Static);

	array.Bind(program, buf, "in_position"s, 3, GL_FLOAT);

	ENTROPY_LOG(AppLog, Severity::Debug) << "MyObject: Finished static initialization";
}

void MyObject::Draw()
{
	shared()->program.SetUniform("in_color"s, glm::vec3(1.0, 0.0, 1.0));

	Bind p(shared()->program), a(shared()->array);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

MyApp::MyApp()
	: Application()
{
	addSearchPath("data");

	setMode(addMode(make_shared<MyMode>(*this)));
}

MyMode::MyMode(MyApp &app)
	: Mode(app)
{
	Current().emplaceDrawable<MyObject>(app);
}

MyObject::MyObject(Application &app)
	: SharedData<::detail::object>(app), Object()
{}

void MyObject::UpdateModel()
{
	shared()->program.SetUniform("model"s, Model());
}

void MyObject::UpdateCamera(const Camera &c)
{
	shared()->program.SetUniform("view"s, c.View());
}

void MyObject::UpdateScreen(const Screen &s)
{
	shared()->program.SetUniform("projection"s, s.Perspective());
}
