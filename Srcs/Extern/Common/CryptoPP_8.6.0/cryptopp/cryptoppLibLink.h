#ifndef _CRYPTOPPLIBLINK_H_
#define _CRYPTOPPLIBLINK_H_

#ifdef _DLL
#ifndef CRYPTOPP_IMPORTS
#define CRYPTOPP_IMPORTS
#endif
#endif

#if defined(CRYPTOPP_IMPORTS)
#include "dll.h"
#else
	#ifdef _WIN32
		#ifdef _DEBUG
			#pragma comment( lib, "../../../Extern/Common/CryptoPP_8.6.0/cryptopp/Win32/Output/Debug/cryptlib.lib" )
		#else
			#pragma comment( lib, "../../../Extern/Common/CryptoPP_8.6.0/cryptopp/Win32/Output/Release/cryptlib.lib" )
		#endif
	#endif
#endif

#endif /* !_CRYPTOPPLIBLINK_H_ */
