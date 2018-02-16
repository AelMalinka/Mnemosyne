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
					virtual void setMode(const PolymorphicList<ModeBase>::iterator &);
					virtual PolymorphicList<ModeBase>::iterator current();
					virtual PolymorphicList<ModeBase>::iterator addMode(const std::shared_ptr<ModeBase> &);
					template<typename F>
					auto load(const std::string &, F) const;
					template<typename T, typename F>
					void write(const std::string &, Handle<T> &, F) const;
					virtual void addSearchPath(const std::string &);
				protected:
					virtual void onEvent(const Entropy::Event &);
				protected:
					virtual std::string findFullPath(const std::string &) const;
					virtual void createPath(const std::string &) const;
				protected:
					PolymorphicList<ModeBase>::iterator begin();
					PolymorphicList<ModeBase>::iterator end();
				private:
					std::list<std::string> _paths;
					PolymorphicList<ModeBase> _modes;
					PolymorphicList<ModeBase>::iterator _current;
			};
		}
	}

#	include "Application.impl.hh"

#endif
