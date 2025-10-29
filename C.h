/******************************************************************************
* \file      C.h
* \version   2026.01.01
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

#ifndef C_H
#define C_H		20260101L


/* C none */
#define NOC							0L

/* non standard *//* do not use */
#define CKR							197801L
#define C78							CKR /* alias */

/* official standard ANSI X3.159-1989 *//* ANSI C */
#define C89							198901L

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
#define C_STD						__STDC__
#else
#define C_STD						0
#endif


/******************************************************************************
* C_VERSION definition, since CKR/C78, ..., C23
*/
#if !defined(__cplusplus) && !defined(__cplusplus_cli) && !defined(__embedded_cplusplus)

#if defined(__STDC_VERSION__)
#define C_VERSION					__STDC_VERSION__
#elif defined(__STDC__)
#define C_VERSION					C89
#else
#define C_VERSION					CKR
#endif

#else

#define C_VERSION					NOC

#endif


/******************************************************************************
* C_STD_HOSTED definition, 1 hosted, 0 not hosted, -1 hosting is unknown
*/
#if defined(__STDC_HOSTED__)
#define C_STD_HOSTED				__STDC_HOSTED__
#else
#define C_STD_HOSTED				-1
#endif


/******************************************************************************
**  Basic GET macros
*/
/* 1 STDC, 0 not STDC */
#define GET_C_STD()					C_STD

/* since CKR/C78, ..., C23 */
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


#endif /* C_H */
