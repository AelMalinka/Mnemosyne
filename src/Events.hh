/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_EVENTS_INC
#	define ENTROPY_MNEMOSYNE_EVENTS_INC

#	include "Event.hh"
#	include "Application.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Events
			{
				class ModeChange :
					public Event
				{
					public:
						static constexpr std::size_t Id = Mnemosyne::Event::First;
						ModeChange(Application &, Mode &);
						Application &getApplication() const;
						Mode &getMode() const;
					private:
						Application &_app;
						Mode &_mode;
				};
			}
		}
	}

#endif
