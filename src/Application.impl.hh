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

				template<typename F, typename = void>
				struct get_extension
				{
					explicit get_extension(const F &f) : _f(f) {}
					std::string operator () () const
					{
						return "";
					}
					private:
						const F &_f;
				};

				template<typename F>
				struct get_extension<
					F,
					typename std::enable_if<
						detail::has_extension<F>::value
					>::type
				>
				{
					explicit get_extension(const F &f) : _f(f) {}
					std::string operator () () const
					{
						return _f.Extension();
					}
					private:
						const F &_f;
				};
			}

			template<typename F>
			auto Application::load(const std::string &path, F f) const
			{
				return f(findFullPath(path + detail::get_extension(f)()));
			}
		}
	}

#endif
