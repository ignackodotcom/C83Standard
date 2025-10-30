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


#if defined(__embedded_cplusplus)
#define ECPP								__embedded_cplusplus
#define ECXX								__embedded_cplusplus
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


#endif /* PECPP_H */
