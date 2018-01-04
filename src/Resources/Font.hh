/*	Copyright 2018 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_FONT_INC
#	define ENTROPY_MNEMOSYNE_RESOURCES_FONT_INC

#	include "Exception.hh"
#	include "../Handle.hh"
#	include <Entropy/Theia/UI/FT/Font.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				class Font
				{
					public:
						explicit Font(const std::size_t = 127, const FT_UInt = 48, const FT_Long = 0, const FT_UInt = 0);
						virtual Handle<Theia::UI::FT::Font> operator () (const std::string &);
					private:
						std::size_t _count;
						FT_UInt _height;
						FT_Long _slot;
						FT_UInt _width;
				};
			}
		}
	}

#endif
