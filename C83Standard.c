/******************************************************************************
* \file      C83Standard.c
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

#include "C83Standard.h"



long C83STANDARD_DATE(void)
{
    return (C83STANDARD_VERSION_DATE);
}

long C83STANDARD_VERSION(void)
{
    return (C83STANDARD_VERSION_NUMBER);
}
