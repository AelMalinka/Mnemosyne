/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_TEST_INTERFACE_INC
#	define ENTROPY_MNEMOSYNE_TEST_INTERFACE_INC

#	include <Entropy/Module.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Test
			{
				class Interface
				{
					public:
						virtual const std::string &Name() const = 0;
						virtual const std::size_t &Value() const = 0;
				};
			}
		}
	}

#endif
