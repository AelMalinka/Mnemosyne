/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_MODE_BASE_INC
#	define ENTROPY_MNEMOSYNE_MODE_BASE_INC

#	include "onEvent.hh"
#	include <Entropy/Theia/Scene.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			class Application;

			class ModeBase
			{
				public:
					ModeBase(Application &);
					virtual ~ModeBase();
					virtual void makeCurrent();
					virtual DefaultedList<Theia::Scene>::iterator addScene();
					virtual void setScene(const DefaultedList<Theia::Scene>::iterator &);
					virtual void onEvent(const Entropy::Event &);
				protected:
					virtual void onUnknownEvent(const Entropy::Event &);
					virtual void onEvent(const Theia::Events::Debug &) {}
					virtual void onEvent(const Theia::Events::Show &) {}
					virtual void onEvent(const Theia::Events::Hide &) {}
					virtual void onEvent(const Theia::Events::Close &) {}
					virtual void onEvent(const Theia::Events::Resize &) {}
					virtual void onEvent(const Theia::Events::Tick &) {}
					virtual void onEvent(const Theia::Events::Key &) {}
					virtual void onEvent(const Theia::Events::Mouse &) {}
					virtual void onEvent(const Events::ModeChange &) {}
					virtual Theia::Scene &Current();
					virtual const Theia::Scene &Current() const;
					DefaultedList<Theia::Scene>::iterator getIterator() const;
				private:
					Application &_app;
					Entropy::Mnemosyne::onEvent _on_event;
					std::list<DefaultedList<Theia::Scene>::iterator> _scenes;
					DefaultedList<Theia::Scene>::iterator _current;
			};
		}
	}

#	include "Application.hh"

#endif
