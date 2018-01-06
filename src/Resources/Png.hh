/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_PNG_ING
#	define ENTROPY_MNEMOSYNE_RESOURCES_PNG_ING

#	include "Exception.hh"
#	include "../Handle.hh"
#	include <Entropy/PNG.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				class Png
				{
					public:
						virtual Handle<PNG> operator () (const std::string &);
						virtual void operator () (const std::string &, Handle<PNG> &); 
						constexpr const char *Extension() const { return ".png"; }
				};
			}
		}
	}

#endif
