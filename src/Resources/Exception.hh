/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_EXCEPTION_INC
#	define ENTROPY_MNEMOSYNE_RESOURCES_EXCEPTION_INC

#	include "../Exception.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				ENTROPY_EXCEPTION(Exception, "Resource Exception", ::Entropy::Mnemosyne::Exception);

				ENTROPY_EXCEPTION(NoFile, "Resource Exception: File Not Found", ::Entropy::Mnemosyne::Resources::Exception);
				ENTROPY_EXCEPTION(WrongType, "Resource Exception: Wrong File Type", ::Entropy::Mnemosyne::Resources::Exception);

				ENTROPY_ERROR_INFO(ResourcePath, std::string);
			}
		}
	}

#endif
