/******************************************************************************
* \file      PC.h
* \version   2026.01.17
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     C Standard definitions
* \details   
*
* \see       https://github.com/ignackodotcom
*			 https://en.wikipedia.org/wiki/C_(programming_language)
*            https://en.cppreference.com/w/c/preprocessor/replace#Predefined_macros
*            https://github.com/cpredef/predef
*			 and other resources
******************************************************************************/

#ifndef PC_H
#define PC_H		20260119L


/* C none */
#define NOC							0L

/* K&R C or non standard C */
#define CKR							197801L
#define C78							CKR /* alias */

/* official standard ANSI X3.159-1989 *//* ANSI C */
#define C89							198901L

/* Legacy MSVC since _MSC_VER 1900 (VS2015+) */
#define C89_MSVC					198902L

/* official standard ISO/IEC 9899:1990 *//* ANSI/ISO C */
#define C90							C89

/* official standard ISO/IEC 9899-1:1994 ISO/IEC 9899/AMD1:1995 *//* ANSI/ISO C */
#define C95							199409L

/* official standard ISO/IEC 9899:1999 *//* ANSI/ISO C */
#define C99							199901L

/* official standard ISO/IEC 9899:2011 *//* ANSI/ISO C */
#define C11							201112L

/* official standard ISO/IEC 9899:2018 *//* ANSI/ISO C */
#define C17							201710L

/* official standard ISO/IEC 9899:2024 *//* ANSI/ISO C */
#define C23							202311L


/******************************************************************************
* C_STD definition, 1 STDC, 0 not STDC
*/
#if defined(__STDC__)
	#define C_STD					__STDC__
#else
	#define C_STD					0
#endif


/******************************************************************************
* C_VERSION definition, since NOC, CKR/C78, ..., C23
*/
#if !defined(__cplusplus) && !defined(__cplusplus_cli) && !defined(__embedded_cplusplus)

	#if defined(__STDC_VERSION__)
		#define C_VERSION			__STDC_VERSION__
	#elif defined(_MSC_VER) && _MSC_VER >= 1900
		/**********************************************************************
		* Legacy MSVC
		* It does not correspond to a single strict ISO C standard version.
		* Instead, it implements:
		* - Not full support for C89/C90 (ISO/IEC 9899:1990, the original standardized C).
		* - Partial support for some C99 features (but not complete conformance).
		* - Various Microsoft-specific extensions and behaviors from older MSVC versions.
		**********************************************************************/ 
		#define C_VERSION			C89_MSVC
	#elif defined(__STDC__)
		#define C_VERSION			C89
	#else
		#define C_VERSION			CKR
	#endif

#else

	#define C_VERSION				NOC

#endif


/******************************************************************************
* C_STD_HOSTED definition, 
*	-   1 hosted (runs under an OS),
*   -   0 freestanding (runs without an OS), 
*   -  -1 hosting is unknown
*/
#if defined(__STDC_HOSTED__)
	#define C_STD_HOSTED			__STDC_HOSTED__
#else
	#define C_STD_HOSTED			-1
#endif


/******************************************************************************
**  Basic GET macros
*/
/* 1 STDC, 0 not STDC */
#define GET_C_STD()					C_STD

/* since NOC, CKR/C78, ..., C23 */
#define GET_C_VERSION()				C_VERSION

#define GET_C_VERSION_YEAR()		(C_VERSION/100L)

/* 1 hosted, 0 not hosted, -1 unknown */
#define GET_C_STD_HOSTED()			C_STD_HOSTED


/******************************************************************************
* Examples of use
*
* #if defined(__STDC_VERSION__) && __STDC_VERSION__ == C99
*	...
*	C99 code
*	...
* #endif
* 
* ---------------------------------------------------------
* #if C_VERSION == CKR
*	...
*	CKR code
*	...
* #elif C_VERSION == C89
*	...
*	C89 code
*	...
* #elif C_VERSION == C95
*	...
*	C95 code
*	...
* #elif C_VERSION == C99
*	...
*	C99 code
*	...
* #else
*	...
*	other code
*	...
* #endif
* 
* ---------------------------------------------------------
* printf("stdc                  = %d\n\r",  GET_C_STD());
* printf("c version             = %ld\n\r", GET_C_VERSION());
* printf("c version year        = %ld\n\r", GET_C_VERSION_YEAR());
* printf("stdc hosted           = %d\n\r",  GET_C_STD_HOSTED());
* printf("\n\r");
*
*/


#endif /* PC_H */
