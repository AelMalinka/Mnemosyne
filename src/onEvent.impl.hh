/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_ONEVENT_IMPL
#	define ENTROPY_MNEMOSYNE_ONEVENT_IMPL

#	include "onEvent.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			template<typename ...Args>
			onEvent::onEvent(Args && ... args)
			{
				assigns(std::forward<Args>(args)...);
			}

			template<typename First, typename ...Rest>
			void onEvent::assigns(First &&f, Rest && ...rest)
			{
				assign(std::forward<First>(f));
				assigns(std::forward<Rest>(rest)...);
			}
		}
	}

#endif
