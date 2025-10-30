/******************************************************************************
* \file      PCppCli.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Cpp Cli Standard definitions
* \details
*
* \see       https://github.com/ignackodotcom
*			 https://en.wikipedia.org/wiki/C%2B%2B/CLI
*            https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170
*            https://github.com/cpredef/predef
*			 and other resources
******************************************************************************/

#ifndef PCPPCLI_H
#define PCPPCLI_H		20260101L


/* cpp cli none */
#define NOCPPCLI							0L
#define NOCXXCLI							NOCPPCLI

#define CPPCLIPRE							1L
#define CXXCLIPRE							CPPCLIPRE /* alias */

/* official standard ECMA-372 script */
#define CPPCLI								200406L
#define CXXCLI								CPPCLI /* alias */


/******************************************************************************
* CPPCLI_VERSION/CXXCLI_VERSION definition, since NOCPPCLI/NOCXXCLI, CPPCLIPRE/CXXCLIPRE, ..., CPPCLI/CXXCLI
*/
#if defined(__cplusplus_cli)
	#if __cplusplus_cli < CPPCLI
		#define CPPCLI_VERSION				CPPCLIPRE
		#define CXXCLI_VERSION				CXXCLIPRE
	#else
		#define CPPCLI_VERSION				__cplusplus_cli
		#define CXXCLI_VERSION				__cplusplus_cli
	#endif
#else
	#define CPPCLI_VERSION					NOCPPCLI
	#define CXXCLI_VERSION					NOCXXCLI
#endif


/******************************************************************************
**  Basic GET macros
*/
/* since NOCPPCLI/NOCXXCLI, CPPCLIPRE/CXXCLIPRE, CPPCLI/CXXCLI */
#define GET_CPPCLI_VERSION()				CPPCLI_VERSION
#define GET_CXXCLI_VERSION()				CXXCLI_VERSION

#define GET_CPPCLI_VERSION_YEAR()			(CPPCLI_VERSION/100L)
#define GET_CXXCLI_VERSION_YEAR()			(CXXCLI_VERSION/100L)


/******************************************************************************
* Example of use
*
* #if defined(__cplusplus_cli) && __cplusplus_cli >= CPPCLI
*	...
*	CPPCLI code
*	...
* #endif
*
* or
* 
* #if defined(__cplusplus_cli) && __cplusplus_cli >= CXXCLI
*	...
*	CPPCLI code
*	...
* #endif
*
* ---------------------------------------------------------
* #if CPPCLI_VERSION == CPPCLIPRE
*	...
*	CPPCLIPRE code
*	...
* #elif CPPCLI_VERSION == CPPCLI
*	...
*	CPPCLI code
*	...
* #else
*	...
*	other code
*	...
* #endif
*
* or
* 
* #if CXXCLI_VERSION == CXXCLIPRE
*	...
*	CPPCLIPRE code
*	...
* #elif CXXCLI_VERSION == CXXCLI
*	...
*	CPPCLI code
*	...
* #else
*	...
*	other code
*	...
* #endif
*
* ---------------------------------------------------------
* printf("cpp cli version      = %ld\n\r", GET_CPPCLI_VERSION());
* printf("cpp cli version year = %ld\n\r", GET_CPPCLI_VERSION_YEAR());
*
* or
* 
* printf("cpp cli version      = %ld\n\r", GET_CXXCLI_VERSION());
* printf("cpp cli version year = %ld\n\r", GET_CXXCLI_VERSION_YEAR());
*
*/


#endif /* PCPPCLI_H */
