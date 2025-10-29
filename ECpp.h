/******************************************************************************
* \file      ECpp.h
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

#ifndef ECPP_H
#define ECPP_H		20260101L


#if defined(__embedded_cplusplus)
#define ECPP								(long)__embedded_cplusplus
#define ECXX								(long)__embedded_cplusplus
#endif /* __embedded_cplusplus */


/******************************************************************************
* Example of use
*
* #if defined(ECPP)
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


#endif /* ECPP_H */
