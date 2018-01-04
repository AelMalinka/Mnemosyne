/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_MODE_INC
#	define ENTROPY_MNEMOSYNE_MODE_INC

#	include "Exception.hh"
#	include <Entropy/Event.hh>
#	include <Entropy/Tethys/Timer.hh>
#	include <Entropy/Theia/Scene.hh>
#	include <list>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			class Application;

			class Mode
			{
				public:
					Mode(Application &);
					virtual ~Mode();
					virtual void makeCurrent();
					virtual DefaultedList<Theia::Scene>::iterator addScene();
					virtual void setScene(const DefaultedList<Theia::Scene>::iterator &);
					virtual void onEvent(const Entropy::Event &) = 0;
				protected:
					virtual Theia::Scene &Current();
					virtual const Theia::Scene &Current() const;
					DefaultedList<Theia::Scene>::iterator getIterator() const;
					virtual Application &App();
					virtual const Application &App() const;
				private:
					Application &_app;
					std::list<DefaultedList<Theia::Scene>::iterator> _scenes;
					DefaultedList<Theia::Scene>::iterator _current;
			};
		}
	}

#	include "Application.hh"

#endif
