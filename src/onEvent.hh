/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_ONEVENT_INC
#	define ENTROPY_MNEMOSYNE_ONEVENT_INC

#	include <functional>
#	include "Exception.hh"
#	include "Events.hh"
#	include <Entropy/Theia/Events.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			// 2018-01-14 AMR TODO: there has to be a cleaner way to do this
			class onEvent
			{
				public:
					template<typename ...Args>
					explicit onEvent(Args && ...);
					void operator () (const Entropy::Event &);
					void setEvent(const std::function<void(const Entropy::Event &)> &);
					void setUnknown(const std::function<void(const Entropy::Event &)> &);
				private:
					void call(const Entropy::Event &);
					void call(const Theia::Events::Debug &);
					void call(const Theia::Events::Show &);
					void call(const Theia::Events::Hide &);
					void call(const Theia::Events::Close &);
					void call(const Theia::Events::Resize &);
					void call(const Theia::Events::Tick &);
					void call(const Theia::Events::Key &);
					void call(const Theia::Events::Mouse &);
					void call(const Events::ModeChange &);
					void unknown(const Entropy::Event &);
				private:
					template<typename First, typename ...Rest>
					void assigns(First &&, Rest && ...);
					void assigns();
				private:
					void assign(const onEvent &);
					void assign(const std::function<void(const Theia::Events::Debug &)> &);
					void assign(const std::function<void(const Theia::Events::Show &)> &);
					void assign(const std::function<void(const Theia::Events::Hide &)> &);
					void assign(const std::function<void(const Theia::Events::Close &)> &);
					void assign(const std::function<void(const Theia::Events::Resize &)> &);
					void assign(const std::function<void(const Theia::Events::Tick &)> &);
					void assign(const std::function<void(const Theia::Events::Key &)> &);
					void assign(const std::function<void(const Theia::Events::Mouse &)> &);
					void assign(const std::function<void(const Events::ModeChange &)> &);
				private:
					std::function<void(const Entropy::Event &)> _event;
					std::function<void(const Entropy::Event &)> _unknown;
					std::function<void(const Theia::Events::Debug &)> _debug;
					std::function<void(const Theia::Events::Show &)> _show;
					std::function<void(const Theia::Events::Hide &)> _hide;
					std::function<void(const Theia::Events::Close &)> _close;
					std::function<void(const Theia::Events::Resize &)> _resize;
					std::function<void(const Theia::Events::Tick &)> _tick;
					std::function<void(const Theia::Events::Key &)> _key;
					std::function<void(const Theia::Events::Mouse &)> _mouse;
					std::function<void(const Events::ModeChange &)> _mode;
			};

			ENTROPY_EXCEPTION(UnknownEvent, "Unknown Event", Exception);
			ENTROPY_ERROR_INFO(EventInfo, Entropy::Event);
		}
	}

#	include "onEvent.impl.hh"

#endif
