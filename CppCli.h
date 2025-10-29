/******************************************************************************
* \file      CppCli.h
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

#ifndef CPPCLI_H
#define CPPCLI_H		20260101L


#define CPPCLIPRE							1L
#define CXXCLIPRE							CPPCLIPRE /* alias */

/* official standard ECMA-372 script */
#define CPPCLI								200406L
#define CXXCLI								CPPCLI /* alias */


/******************************************************************************
* CPPCLI_VERSION/CXXCLI_VERSION definition, since CPPCLIPRE/CXXCLIPRE, ..., CPPCLI/CXXCLI
*/
#if defined(__cplusplus_cli)
#define CPPCLI_VERSION						(long)__cplusplus_cli
#define CXXCLI_VERSION						(long)__cplusplus_cli
#else
#define CPPCLI_VERSION						CPPCLIPRE
#define CXXCLI_VERSION						CXXCLIPRE
#endif


/******************************************************************************
**  Basic GET macros
*/
/* since CPPCLIPRE/CXXCLIPRE, CPPCLI/CXXCLI */
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


#endif /* CPPCLI_H */
