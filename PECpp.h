/******************************************************************************
* \file      PECpp.h
* \version   2026.01.01
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     Embedded Cpp Standard definitions
* \details
*
* \see       https://github.com/ignackodotcom
*            https://github.com/cpredef/predef
*			 and other resources
******************************************************************************/

#ifndef PECPP_H
#define PECPP_H		20260101L


/* ecpp none */
#define NOECPP								0L
#define NOECXX								NOECPP /* alias */


#if defined(__embedded_cplusplus)
	#define ECPP_VERSION					__embedded_cplusplus
	#define ECXX_VERSION					__embedded_cplusplus
#else 
	#define ECPP_VERSION					NOECPP
	#define ECXX_VERSION					NOECXX
#endif /* __embedded_cplusplus */


/******************************************************************************
**  Basic GET macros
*/
/* since NOECPP/NOECXX */
#define GET_ECPP_VERSION()					ECPP_VERSION
#define GET_ECXX_VERSION()					ECXX_VERSION


/******************************************************************************
* Example of use
*
* #if ECPP != NO
*	...
*	ECPP code
*	...
* #endif
* 
* or
* 
* #if defined(ECXX)
*	...
*	ECPP code
*	...
* #endif
*
*/


#endif /* PECPP_H */
