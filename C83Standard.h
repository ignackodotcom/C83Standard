/******************************************************************************
* \file      C83Standard.h
* \version   2026.01.17 26.00.01.01 (YYYYMMDD XXYYZZWW)
* \author    Peter Potrok ( @ignackodotcom )
*            ignacko.com@outlook.com
*            https://github.com/ignackodotcom
* \copyright Copyright (c) 1994 - 2026
*            MIT License (see License.txt file)
* \brief     C, Cpp, CppCli, DspC, ECpp standards identification macros for C and C++ library
* \details
*
* \see       https://github.com/ignackodotcom
*            and other resources
******************************************************************************/

#ifndef C83STANDARD_H
#define C83STANDARD_H



#include "PC.h"
#include "PCpp.h"
#include "PCppCli.h"
#include "PDspC.h"
#include "PECpp.h"



/******************************************************************************
* version date format YYYYMMDD
*/
#define C83STANDARD_VERSION_DATE	20260119L

/******************************************************************************
* version number format XXYYZZWW
*/
#define C83STANDARD_VERSION_NUMBER  26000103L



#ifdef __cplusplus
extern "C" {
#endif

    long C83STANDARD_DATE(void);
    long C83STANDARD_VERSION(void);

#ifdef __cplusplus
}
#endif



#endif /* C83STANDARD_H */
