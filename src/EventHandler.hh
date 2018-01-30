/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_EVENTHANDLER_INC
#	define ENTROPY_MNEMOSYNE_EVENTHANDLER_INC

#	include "onEvent.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			class EventHandler
			{
				public:
					EventHandler();
					virtual ~EventHandler();
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
				private:
					Entropy::Mnemosyne::onEvent _on_event;
			};
		}
	}

#endif
