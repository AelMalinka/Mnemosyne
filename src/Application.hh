/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_APPLICATION_INC
#	define ENTROPY_MNEMOSYNE_APPLICATION_INC

#	include "Exception.hh"
#	include <Entropy/Aoede/Application.hh>
#	include <Entropy/Theia/Application.hh>
#	include <Entropy/PolymorphicList.hh>

#	include "Mode.hh"
#	include "Handle.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			ENTROPY_EXCEPTION(NoMode, "No Game Mode Loaded", Exception);

			class Application :
				public Aoede::Application,
				public Theia::Application
			{
				public:
					Application();
					Application(const int, char *[]);
					virtual ~Application();
					virtual void operator () ();
					virtual Mode &getMode();
					virtual void setMode(const PolymorphicList<Mode>::iterator &);
					virtual PolymorphicList<Mode>::iterator addMode(const std::shared_ptr<Mode> &);
					template<typename F>
					auto load(const std::string &, F) const;
					// 2018-01-06 AMR TODO: saving non-existant file
					template<typename T, typename F>
					void write(const std::string &, Handle<T> &, F) const;
					virtual void addSearchPath(const std::string &);
				protected:
					virtual void onEvent(const Entropy::Event &);
				protected:
					virtual std::string findFullPath(const std::string &) const;
				protected:
					PolymorphicList<Mode>::iterator begin();
					PolymorphicList<Mode>::iterator end();
				private:
					std::list<std::string> _paths;
					PolymorphicList<Mode> _modes;
					PolymorphicList<Mode>::iterator _current;
			};
		}
	}

#	include "Application.impl.hh"

#endif
