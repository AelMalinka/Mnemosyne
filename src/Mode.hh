/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_MODE_INC
#	define ENTROPY_MNEMOSYNE_MODE_INC

#	include "Exception.hh"
#	include <Entropy/Tethys/Timer.hh>
#	include <Entropy/Event.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			class Mode
			{
				public:
					Mode();
					virtual ~Mode();
					virtual void onEvent(const Entropy::Event &) = 0;
			};
		}
	}

#endif
