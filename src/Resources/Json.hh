/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_RESOURCES_JSON_INC
#	define ENTROPY_MNEMOSYNE_RESOURCES_JSON_INC

#	include "Exception.hh"
#	include "../Handle.hh"
#	include <json/json.h>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace Resources
			{
				ENTROPY_EXCEPTION(JsonError, "Json Parse Error", Exception);

				class Json
				{
					public:
						virtual Handle<::Json::Value> operator () (const std::string &);
						virtual void operator () (const std::string &, Handle<::Json::Value> &);
						constexpr const char *Extension() const { return ".json"; }
				};
			}
		}
	}

#endif
