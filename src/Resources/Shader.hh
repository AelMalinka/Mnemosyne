/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_SHADER_INC
#	define ENTROPY_MNEMOSYNE_RESOURCES_SHADER_INC

#	include "Exception.hh"
#	include "../Handle.hh"
#	include <Entropy/Theia/GL/Shader.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				class Shader
				{
					public:
						virtual Handle<Theia::GL::Shader> operator () (const std::string &);
				};
			}
		}
	}

#endif
