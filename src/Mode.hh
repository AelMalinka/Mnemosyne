/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_MODE_INC
#	define ENTROPY_MNEMOSYNE_MODE_INC

#	include "ModeBase.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			template<typename Application>
			class Mode :
				public ModeBase
			{
				public:
					Mode(Application &);
					virtual ~Mode();
				protected:
					virtual Application &App();
					virtual const Application &App() const;
				private:
					Application &_app;
			};
		}
	}

#	include "Mode.impl.hh"

#endif
