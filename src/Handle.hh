/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_HANDLE_INC
#	define ENTROPY_MNEMOSYNE_HANDLE_INC

#	include "Exception.hh"
#	include <memory>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			template<typename T>
			class Handle
			{
				public:
					Handle();
					explicit Handle(T *);
					Handle(const std::shared_ptr<T> &);
					Handle(const Handle<T> &);
					Handle(Handle<T> &&);
					virtual ~Handle();
					T *get();
					const T *get() const;
					const std::shared_ptr<T> &shared() const;
					Handle &operator = (const Handle<T> &);
					Handle &operator = (Handle<T> &&);
					T &operator *();
					T *operator -> ();
					const T &operator *() const;
					const T *operator -> () const;
					operator const std::shared_ptr<T> &() const;
				private:
					std::shared_ptr<T> _data;
			};
		}
	}

#	include "Handle.impl.hh"

#endif
