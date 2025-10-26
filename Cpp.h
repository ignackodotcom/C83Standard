/******************************************************************************
* \file      Cpp.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Cpp Standard definitions
* \details
*
* \see       https://github.com/ignackodotcom
*			 https://en.wikipedia.org/wiki/C%2B%2B
*            https://en.cppreference.com/w/cpp/preprocessor/replace#Predefined_macros
*            https://github.com/cpredef/predef
*			 and other resources
******************************************************************************/

#ifndef CPP_H
#define CPP_H		20260101L


#define CPPPRE							1L
#define CXXPRE							CPPPRE /* alias */

/* official standard 14882:1998 *//* ANSI/ISO C++ */
#define CPP98							199711L
#define CXX98							CPP98 /* alias */

/* official standard 14882:2003 *//* ANSI/ISO C++ *//* small changes */
/* (remains the same as C++98) */
#define CPP03							CPP98
#define CXX03							CPP03 /* alias */

/* official standard 14882:2011 *//* ANSI/ISO C++ */
#define CPP11							201103L
#define CXX11							CPP11 /* alias */

/* official standard 14882:2014 *//* ANSI/ISO C++ */
#define CPP14							201402L
#define CXX14							CPP14 /* alias */

/* official standard 14882:2017 *//* ANSI/ISO C++ */
#define CPP17							201703L
#define CXX17							CPP17 /* alias */

/* official standard 14882:2020 *//* ANSI/ISO C++ */
#define CPP20							202002L
#define CXX20							CPP20 /* alias */

/* official standard 14882:2024 *//* ANSI/ISO C++ */
#define CPP23							202302L
#define CXX23							CPP23 /* alias */


/******************************************************************************
* CPP_VERSION/CXX_VERSION definition, since CPPPRE/CXXPRE, ..., CPP23/CXX23
*/
#if defined(__cplusplus)
#define CPP_VERSION						__cplusplus
#define CXX_VERSION						__cplusplus
#else
#define CPP_VERSION						CPPPRE
#define CXX_VERSION						CXXPRE
#endif


/******************************************************************************
**  Basic GET macros
*/
/* since CPPPRE/CXXPRE, ..., CPP23/CXX23 */
#define GET_CPP_VERSION()				CPP_VERSION
#define GET_CXX_VERSION()				CXX_VERSION

#define GET_CPP_VERSION_YEAR()			(CPP_VERSION/100L)
#define GET_CXX_VERSION_YEAR()			(CXX_VERSION/100L)


/******************************************************************************
* Examples of use
*
* #if defined(__cplusplus) && __cplusplus == CPP11
*	...
*	CPP11 code
*	...
* #endif
*
* or
* 
* #if defined(__cplusplus) && __cplusplus == CXX11
*	...
*	CPP11 code
*	...
* #endif
*
* ---------------------------------------------------------
* #if CPP_VERSION == CPPPRE
*	...
*	CPPPRE code
*	...
* #elif CPP_VERSION == CPP98
*	...
*	CPP98 code
*	...
* #elif CPP_VERSION == CPP11
*	...
*	CPP11 code
*	...
* #else
*	...
*	other code
*	...
* #endif
* 
* or
* 
* #if CXX_VERSION == CXXPRE
*	...
*	CPPPRE code
*	...
* #elif CXX_VERSION == CXX98
*	...
*	CPP98 code
*	...
* #elif CXX_VERSION == CXX11
*	...
*	CPP11 code
*	...
* #else
*	...
*	other code
*	...
* #endif
*
* ---------------------------------------------------------
* printf("cpp version      = %ld\n\r", GET_CPP_VERSION());
* printf("cpp version year = %ld\n\r", GET_CPP_VERSION_YEAR());
* 
* or
* 
* printf("cpp version      = %ld\n\r", GET_CXX_VERSION());
* printf("cpp version year = %ld\n\r", GET_CXX_VERSION_YEAR());
*
*/


#endif /* CPP_H */
