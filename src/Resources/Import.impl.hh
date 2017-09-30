/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_IMPORT_IMPL
#	define ENTROPY_MNEMOSYNE_RESOURCES_IMPORT_IMPL

#	include "Import.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				template<typename Interface>
				Entropy::Import<Interface> Import<Interface>::operator () (const std::string &path)
				{
					return Entropy::Import<Interface>(path);
				}
			}
		}
	}

#endif
