/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_MNEMOSYNE_EXCEPTION_INC
#	define ENTROPY_MNEMOSYNE_EXCEPTION_INC

	// 2017-09-19 AMR HACK: while Tethys::Timer is Tethys::UV::Timer have to include here
	// 2017-09-19 AMR NOTE: have to inlcude uv.h before windows.h
#	include <Entropy/Tethys/Timer.hh>

#	include <Entropy/Theia/Exception.hh>
#	include <Entropy/Aoede/Exception.hh>

	namespace Entropy
	{
		namespace Mnemosyne
		{
			ENTROPY_EXCEPTION_BASE(Exception, "Mnemosyne Exception");

			extern Log::Logger Log;
		}
	}

#endif
