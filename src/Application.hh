/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_APPLICATION_INC
#	define ENTROPY_MNEMOSYNE_APPLICATION_INC

#	include "Exception.hh"
#	include <Entropy/Aoede/Application.hh>
#	include <Entropy/Theia/Application.hh>
#	include <list>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			class Application :
				public virtual Aoede::Application,
				public virtual Theia::Application
			{
				public:
					Application();
					Application(const int, char *[]);
					virtual ~Application();
					template<typename F>
					auto load(const std::string &, F) const;
					virtual void addSearchPath(const std::string &);
				protected:
					virtual std::string findFullPath(const std::string &) const;
				private:
					std::list<std::string> _paths;
			};
		}
	}

#	include "Application.impl.hh"

#endif
