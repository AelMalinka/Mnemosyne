/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_FILE_INC
#	define ENTROPY_MNEMOSYNE_RESOURCES_FILE_INC

#	include "Exception.hh"
#	include "../Handle.hh"
#	include <fstream>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				class File
				{
					public:
						virtual Handle<std::fstream> operator () (const std::string &);
						virtual void operator () (const std::string &, Handle<std::fstream> &);
				};
			}
		}
	}

#endif
