/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCE_TEXTURE_INC
#	define ENTROPY_MNEMOSYNE_RESOURCE_TEXTURE_INC

#	include "Exception.hh"
#	include "../Handle.hh"
#	include <Entropy/Theia/GL/Texture.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				class Texture
				{
					public:
						Texture(const Theia::GL::Texture::Type &);
						virtual Handle<Theia::GL::Texture> operator () (const std::string &);
					private:
						Theia::GL::Texture::Type _type;
				};
			}
		}
	}

#endif
