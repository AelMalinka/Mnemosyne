/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_MODE_IMPL
#	define ENTROPY_MNEMOSYNE_MODE_IMPL

#	include "Mode.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			template<typename Application>
			Mode<Application>::Mode(Application &a)
				: ModeBase(a), _app(a)
			{}

			template<typename Application> Mode<Application>::~Mode() = default;

			template<typename Application>
			Application &Mode<Application>::App()
			{
				return _app;
			}

			template<typename Application>
			const Application &Mode<Application>::App() const
			{
				return _app;
			}
		}
	}

#endif
