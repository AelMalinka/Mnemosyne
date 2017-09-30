/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_EVENT_INC
#	define ENTROPY_MNEMOSYNE_EVENT_INC

#	include "Exception.hh"
#	include <Entropy/Event.hh>
#	include <Entropy/Theia/Event.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			class Event :
				public Entropy::Event
			{
				public:
					Event(const std::size_t &);
					virtual ~Event();
					static constexpr std::size_t First = Theia::Event::Last + 1;
					static constexpr std::size_t Last = First + 10;
			};
		}
	}

#endif
