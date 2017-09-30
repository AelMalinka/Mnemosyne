/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_IMPORT_INC
#	define ENTROPY_MNEMOSYNE_RESOURCES_IMPORT_INC

#	include "Exception.hh"
#	include "../Handle.hh"
#	include <Entropy/Import.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				// 2017-09-29 AMR TODO: windows dlls (and .dll extension)
				template<typename Interface>
				class Import
				{
					public:
						Entropy::Import<Interface> operator () (const std::string &);
						constexpr const char *Extension() const;
				};
			}
		}
	}

#	include "Import.impl.hh"

#endif
