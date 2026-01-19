# C83Standard

## C, Cpp, CppCli, DspC, ECpp standards identification macros for C and C++

3rd edition of the library

part of the C83Project<br>
support for 8.3 file naming conventions with the exception of the main include and code files<br>
support CKR(K&R C) and higher editions<br>


## Overview
C83Standard is a lightweight, portable, header‑based C/C++ utility library 
designed to detect the active language standard used by the compiler. 
It supports strict 8.3 filename conventions, making it suitable for embedded systems, 
legacy toolchains, DOS‑based environments, and cross‑platform builds.


## Features
- C language standards from CKR(K&R C) to C23
- Detects hosted / freestanding C standard
- C++ language standards from CPPPRE(pre-standard) to CPP23
- C++ CLI language standards from CPPCLIPRE(pre-standard) to CPPCLI
- Detects Embedded C++ mode
- DSP‑C (reserved for future use)

## Design Goals

### Primary Objectives
- Provide a unified, compiler‑agnostic way to detect language standards.
- Work with old, modern, and embedded compilers.
- Maintain 8.3 filename compatibility.
- Avoid dependencies and remain header‑only (except for the version function).

### Key Principles
- Simplicity: Easy to integrate and use.
- Predictability: All macros follow consistent naming conventions.
- Portability: Works across GCC, Clang, MSVC, Turbo C++, and embedded compilers.
- Minimalism: Only preprocessor logic, no runtime overhead except for version function.
- Transparency: Exposes all detected values via simple macros.

## Repository Structure
| Filename      | Description                            |
|---------------|----------------------------------------|
| C83Standard.h | Main include file, exposes version API |
| C83Standard.c | Implementation of version function     |
| PC.h          | C standard detection macros            |
| PCpp.h	    | C++ standard detection macros          |
| PCppCli.h	    | C++/CLI standard detection macros      |
| PDspC.h	    | DSP‑C placeholder definitions          |
| PECpp.h	    | Embedded C++ detection macros          |
| License.txt	| MIT License file                       |
| README.md	    | Usage examples and project notes 	     |

## C Standard Detection (PC.h)

### Detection Macros
| Macro        | Description                           |
|--------------|---------------------------------------|
| C_STD        | 1 if \_\_STDC__ is defined, otherwise 0 |
| C_VERSION    | Numeric C standard version            |
| C_STD_HOSTED | 1 hosted, 0 freestanding, -1 unknown  |

### Supported C Standards
| Macro    | Meaning                                                |
|----------|--------------------------------------------------------|
| CKR      | K&R C (pre-ANSI) or Non standard C                     |
| C89      | ANSI C (C89/C90)                                       |
| C95      | ISO C95                                                |
| C99      | ISO C99                                                |
| C11      | ISO C11                                                |
| C17      | ISO C17                                                |
| C23      | ISO C23                                                |
| NOC      | Not a C environment (e.g., compiling as C++)           |

Note: Legacy MSVC
It does not correspond to a single strict ISO C standard version.
Instead, it implements:
- Not full support for C89/C90 (ISO/IEC 9899:1990, the original standardized C).
- Partial support for some C99 features (but not complete conformance).
- Various Microsoft-specific extensions and behaviors from older MSVC versions.

## C++ Standard Detection (PCpp.h)

### Detection Macros
| Macro       | Description                           |
|-------------|---------------------------------------|
| CPP_VERSION | Numeric C++ standard version          |

### Supported C++ Standards
| Macro   | Meaning                                      |
|---------|----------------------------------------------|
| CPPPRE  | Pre-standard C++                             |
| CPP98   | C++98                                        |
| CPP03   | C++03                                        |
| CPP11   | C++11                                        |
| CPP14   | C++14                                        |
| CPP17   | C++17                                        |
| CPP20   | C++20                                        |
| CPP23   | C++23                                        |
| NOCPP   | Not a C++ environment (e.g., compiling as C) |

### Alias Macros
| Alias   | Original Macro               |
|---------|------------------------------|
| CXXPRE  | CPPPRE                       |
| CXX98   | CPP98                        |
| CXX03   | CPP03                        |
| CXX11   | CPP11                        |
| CXX14   | CPP14                        |
| CXX17   | CPP17                        |
| CXX20   | CPP20                        |
| CXX23   | CPP23                        |
| NOCXX   | NOCPP                        |

## C++/CLI Standard Detection (PCppCli.h)

### Detection Macros
| Macro          | Description                           |
|----------------|---------------------------------------|
| CPPCLI_VERSION | Numeric C++ CLI standard version      |

### Supported C++/CLI Standards
| Macro      | Meaning                                                 |
|------------|---------------------------------------------------------|
| CPPCLIPRE  | Pre-standard C++/CLI                                    |
| CPPCLI     | C++/CLI                                                 |
| NOCPPCLI   | Not a C++ CLI environment                               |


### Alias Macros
| Alias      | Original Macro               |
|------------|------------------------------|
| CXXCLIPRE  | CPPCLIPRE                    |
| CXXCLI     | CPPCLI                       |
| NOCXXCLI   | NOCPPCLI                     |

## Embedded C++ Detection (PECpp.h)

### Detection Macros
| Macro        | Description                           |
|--------------|---------------------------------------|
| ECPP_VERSION | Numeric EC++ version                  |

### Supported Values
| Macro        | Meaning                       |
|--------------|-------------------------------|
| NOECPP       | Embedded C++ not active       |

## DSP‑C Detection (PDspC.h)
Currently only a placeholder.
Reserved for future expansion.

## Usage

### Detecting C Standard
To check which C standard is being used, you can use the predefined macros in conditional compilation blocks.

### C Version Detection Example (Conditional Compilation)
```c
#if C_VERSION == CKR
    ...
    CKR code
    ...
#elif C_VERSION == C89
    ...
    C89 code
    ...
#elif C_VERSION == C95
    ...
    C95 code
    ...
#elif C_VERSION == C99
    ...
    C99 code
    ...
#else
    ...
    other code
    ...
#endif
```

### Hosted vs Freestanding Example (Conditional Compilation)
```c
#if C_STD_HOSTED == 1
...
hosted code
...
#elif C_STD_HOSTED == 0
...
freestanding code
...
#else
...
unknown environment code
...
#endif
```

### Detecting C++ Standard
To check which C++ standard is being used, you can use the predefined macros in conditional compilation blocks.

### C++ Version Detection Example (Conditional Compilation)
```c
#if CPP_VERSION == CPPPRE
    ...
    CPPPRE code
    ...
#elif CPP_VERSION == CPP98
    ...
    CPP98 code
    ...
#elif CPP_VERSION == CPP11
    ...
    CPP11 code
    ...
#else
    ...
    other code
    ...
#endif

or using alias
 
#if CXX_VERSION == CXXPRE
    ...
    CPPPRE code
    ...
#elif CXX_VERSION == CXX98
    ...
    CPP98 code
    ...
#elif CXX_VERSION == CXX11
    ...
    CPP11 code
    ...
#else
    ...
    other code
    ...
#endif
```

### Cross Compilation Example (Conditional Compilation)
```c
#if C_VERSION >= C17 || CPP_VERSION >= CPP17
    ...
    Cross code
    ...
#endif
```

### Detecting C++/CLI Standard
To check which C++/CLI standard is being used, you can use the predefined macros in conditional compilation blocks.

### C++ CLI Version Detection Example (Conditional Compilation)
```c
#if CPPCLI_VERSION == CPPCLIPRE
    ...
    CPPCLIPRE code
    ...
#elif CPPCLI_VERSION == CPPCLI
    ...
    CPPCLI code
    ...
#else
    ...
    other code
    ...
#endif

or

#if CXXCLI_VERSION == CXXCLIPRE
    ...
    CPPCLIPRE code
    ...
#elif CXXCLI_VERSION == CXXCLI
    ...
    CPPCLI code
    ...
#else
    ...
    other code
    ...
#endif
```

### Detecting Embedded C++
To check if Embedded C++ mode is active, you can use the predefined macros in conditional compilation blocks.

### Embedded C++ Detection Example (Conditional Compilation)
```c
#if ECPP_VERSION > NOECPP
    ...
    ECPP code
    ...
#endif

or

#if ECXX_VERSION > NOECXX
    ...
    ECPP code
    ...
#endif
```

## Example of versions detection
```c
printf("C83STANDARD Library version = %ld %ld\r\n", C83STANDARD_DATE(), C83STANDARD_VERSION());
printf("\r\n");

/* versions detection 1 */
printf("First C               = %ld\r\n", CKR);
printf("Last C                = %ld\r\n", C23);
printf("Current C             = %ld\r\n", C_VERSION);
printf("\r\n");

printf("First CPP             = %ld\r\n", CPPPRE);
printf("Last CPP              = %ld\r\n", CPP23);
printf("Current CPP           = %ld\r\n", CPP_VERSION);
printf("\r\n");

printf("First CXX             = %ld\r\n", CXXPRE);
printf("Last CXX              = %ld\r\n", CXX23);
printf("Current CXX           = %ld\r\n", CXX_VERSION);
printf("\r\n");

printf("First CPP CLI         = %ld\r\n", CPPCLIPRE);
printf("Last CPP CLI          = %ld\r\n", CPPCLI);
printf("Current CPP CLI       = %ld\r\n", CPPCLI_VERSION);
printf("\r\n");

printf("First CXX CLI         = %ld\r\n", CXXCLIPRE);
printf("Last CXX CLI          = %ld\r\n", CXXCLI);
printf("Current CXX CLI       = %ld\r\n", CXXCLI_VERSION);
printf("\r\n");

printf("Current ECPP          = %ld\r\n", ECPP_VERSION);
printf("\r\n");

printf("Current ECXX          = %ld\r\n", ECXX_VERSION);
printf("\r\n");

/* versions detection 2 */
printf("stdc                  = %d\r\n",  GET_C_STD());
printf("c version             = %ld\r\n", GET_C_VERSION());
printf("c version year        = %ld\r\n", GET_C_VERSION_YEAR());
printf("stdc hosted           = %d\r\n",  GET_C_STD_HOSTED());
printf("\r\n");

printf("cpp version           = %ld\r\n", GET_CPP_VERSION());
printf("cpp version year      = %ld\r\n", GET_CPP_VERSION_YEAR());
printf("\r\n");

printf("cxx version           = %ld\r\n", GET_CXX_VERSION());
printf("cxx version year      = %ld\r\n", GET_CXX_VERSION_YEAR());
printf("\r\n");

printf("cpp cli version       = %ld\r\n", GET_CPPCLI_VERSION());
printf("cpp cli version year  = %ld\r\n", GET_CPPCLI_VERSION_YEAR());
printf("\r\n");

printf("cxx cli version       = %ld\r\n", GET_CXXCLI_VERSION());
printf("cxx cli version year  = %ld\r\n", GET_CXXCLI_VERSION_YEAR());
printf("\r\n");

printf("ecpp version          = %ld\r\n", GET_ECPP_VERSION());
printf("\r\n");

printf("ecxx version          = %ld\r\n", GET_ECXX_VERSION());
printf("\r\n");
```

## Compiler Compatibility
| Compiler           | C Detection                            | C++ Detection     | C++/CLI Detection | Embedded C++ Detection | Notes                   |
|--------------------|----------------------------------------|-------------------|-------------------|------------------------|-------------------------|
| GCC                | Yes                                    | Yes               | No                | No                     |                         |
| Clang              | Yes                                    | Yes               | No                | No                     |                         |
| MSVC               | Yes (With C89 fallback if Legacy MSVC) | Yes               | Yes               | No                     |                         |
| Turbo C++          | Yes                                    | Yes (Uses CPPPRE) | No                | No                     | Limited modern support  |
| Embedded Compilers | Yes / (Varies)                         | Yes / (Varies)    | No                | Yes                    | Check specific compiler |

## Best Practices
- Use macros for conditional compilation.
- Print detected versions for debugging.
- Use aliases (CXX, CPP) interchangeably.

## Avoid
- Mixing C and C++ detection macros incorrectly.

## License
This library is licensed under the MIT License. See the LICENSE file for details.


# Updates
| YYYY MM DD | XX YY ZZ WW | Brief description of updates                           |
|------------|-------------|--------------------------------------------------------|
| 2025 10 29 |             | Fixed error when detecting __cplusplus for Turbo C++   |
| 2025 10 29 |             | NOC, NOCPP/NOCXX, NOCPPCLI/NOCXXCLI defines added      |
| 2025 10 30 |             | C.h renamed to PC.h                                    |
| 2025 10 30 |             | Cpp.h renamed to PCpp.h                                |
| 2025 10 30 |             | CppCli.h renamed to PCppCli.h                          |
| 2025 10 30 |             | DspC.h renamed to PDspC.h                              |
| 2025 10 30 |             | ECpp.h renamed to PECpp.h                              |
| 2025 10 30 |             | Description bug fixed                                  |
| 2026 01 15 |             | Updated README.md for clarity and completeness         |
| 2026 01 15 |             | Added support for Legacy MSVC as C89                   |
| 2026 01 15 |             | Added NOECPP and NOECXX identification macros for ECPP |
| 2026 01 16 |             | Removed support for Legacy MSVC as C89, bug fixed      |
| 2026 01 17 | 26 00 01 01 | Added full support for Legacy MSVC as C89_MSVC         |
| 2026 01 17 | 26 00 01 01 | Project versioning modified                            |
| 2026 01 19 | 26 00 01 02 | Modified comment for CKR (K&R C or non-standard C) in PC.h |
| 2026 01 19 | 26 00 01 02 | Modified comment in Legacy MSVC in PC.h |
| 2026 01 19 | 26 00 01 02 | Improved detection of legacy C89_MSVC from version _MSC_VER 1900 (VS2015+) |
| 2026 01 19 | 26 00 01 03 | Supported C Standards table actualized |
| 2026 01 19 | 26 00 02 01 | C89_MSVC definitively removed as nonsystematic option |
