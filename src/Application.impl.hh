/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_APPLICATION_IMPL
#	define ENTROPY_MNEMOSYNE_APPLICATION_IMPL

#	include "Application.hh"

#	include <type_traits>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			namespace detail
			{
				template<typename T, typename = void>
				struct has_extension : std::false_type {};

				template<typename T>
				struct has_extension<T,
					typename std::enable_if<
						std::is_convertible<decltype(
							std::declval<T>().Extension()
						), std::string>::value
					>::type
				> : std::true_type {};
			}

			template<typename F>
			auto Application::load(const std::string &path, F f) const
			{
				if(detail::has_extension<F>::value)
					return f(findFullPath(path + f.Extension()));
				else
					return f(findFullPath(path));
			}
		}
	}

#endif
