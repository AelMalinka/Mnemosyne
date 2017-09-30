/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_APPLICATION_INC
#	define ENTROPY_MNEMOSYNE_APPLICATION_INC

#	include "Exception.hh"
#	include <Entropy/Aoede/Application.hh>
#	include <Entropy/Theia/Application.hh>
#	include <Entropy/Theia/Utility/PolymorphicList.hh>

#	include "Mode.hh"

	namespace Entropy
	{
		namespace Mnemosyne
		{
			ENTROPY_EXCEPTION(NoMode, "No Game Mode Loaded", Exception);

			class Application :
				public virtual Aoede::Application,
				public virtual Theia::Application
			{
				public:
					Application();
					Application(const int, char *[]);
					virtual ~Application();
					virtual void operator () ();
					virtual Mode &getMode();
					virtual void setMode(const Theia::PolymorphicList<Mode>::iterator &);
					virtual void addMode(const std::shared_ptr<Mode> &);
					template<typename F>
					auto load(const std::string &, F) const;
					virtual void addSearchPath(const std::string &);
				protected:
					virtual void onEvent(const Entropy::Event &);
				protected:
					virtual std::string findFullPath(const std::string &) const;
				private:
					std::list<std::string> _paths;
					Theia::PolymorphicList<Mode> _modes;
					Theia::PolymorphicList<Mode>::iterator _current;
			};
		}
	}

#	include "Application.impl.hh"

#endif
