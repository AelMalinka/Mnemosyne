/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_APPLICATION_IMPL
#	define ENTROPY_MNEMOSYNE_APPLICATION_IMPL

#	include "Application.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			template<typename F>
			auto Application::load(const std::string &path, F f) const
			{
				return f(findFullPath(path));
			}
		}
	}

#endif
