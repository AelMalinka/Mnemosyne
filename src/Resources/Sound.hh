/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_SOUND_INC
#	define ENTROPY_MNEMOSYNE_RESOURCES_SOUND_INC

#	include "Exception.hh"
#	include "../Handle.hh"
#	include <Entropy/Aoede/Sound.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				class Sound
				{
					public:
						explicit Sound(const bool Repeat = false);
						virtual Handle<Aoede::Sound> operator () (const std::string &);
						constexpr const char *Extension() const { return ".flac"; }
					private:
						bool _repeat;
				};
			}
		}
	}

#endif
