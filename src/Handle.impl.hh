/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_HANDLE_IMPL
#	define ENTROPY_MNEMOSYNE_HANDLE_IMPL

	namespace Entropy
	{
		namespace Mnemosyne
		{
			template<typename T> Handle<T>::Handle() = default;
			template<typename T> Handle<T>::Handle(const Handle<T> &) = default;
			template<typename T> Handle<T>::Handle(Handle<T> &&) = default;
			template<typename T> Handle<T>::~Handle() = default;
			template<typename T> Handle<T> &Handle<T>::operator = (const Handle<T> &) = default;
			template<typename T> Handle<T> &Handle<T>::operator = (Handle<T> &&) = default;

			template<typename T>
			Handle<T>::Handle(T *ptr)
				: _data(ptr)
			{}

			template<typename T>
			Handle<T>::Handle(const std::shared_ptr<T> &o)
				: _data(o)
			{}

			template<typename T>
			T *Handle<T>::get()
			{
				return _data.get();
			}

			template<typename T>
			T &Handle<T>::operator *()
			{
				return _data.operator *();
			}

			template<typename T>
			T *Handle<T>::operator -> ()
			{
				return _data.operator->();
			}

			template<typename T>
			const T *Handle<T>::get() const
			{
				return _data.get();
			}

			template<typename T>
			const T &Handle<T>::operator *() const
			{
				return _data.operator *();
			}

			template<typename T>
			const T *Handle<T>::operator -> () const
			{
				return _data.operator->();
			}

			template<typename T>
			const std::shared_ptr<T> &Handle<T>::shared()
			{
				return _data;
			}

			template<typename T>
			Handle<T>::operator const std::shared_ptr<T> &()
			{
				return _data;
			}

			template<typename T>
			Handle<T>::operator bool() const
			{
				return _data.operator bool();
			}
		}
	}

#endif
