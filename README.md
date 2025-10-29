# C83Standard

3rd edition of the library

part of the C83Project<br>
support for 8.3 file naming conventions with the exception of the main include and code files<br>
support C89 and higher editions<br>

c, cpp, cppcli, dspc, ecpp standards identification macros

<br>

Example of use
```c
    printf("STANDARD test\n\r");
    printf("\n\r");

    printf("C83STANDARD_VERSION() = %ld\n\r", C83STANDARD_VERSION());
    printf("\n\r");

    printf("First C               = %ld\n\r", CKR);
    printf("Last C                = %ld\n\r", C23);
    printf("Current C             = %ld\n\r", C_VERSION);
    printf("\n\r");

    printf("First CPP             = %ld\n\r", CPPPRE);
    printf("Last CPP              = %ld\n\r", CPP23);
    printf("Current CPP           = %ld\n\r", CPP_VERSION);
    printf("\n\r");

    printf("First CXX             = %ld\n\r", CXXPRE);
    printf("Last CXX              = %ld\n\r", CXX23);
    printf("Current CXX           = %ld\n\r", CXX_VERSION);
    printf("\n\r");

    printf("First CPP CLI         = %ld\n\r", CPPCLIPRE);
    printf("Last CPP CLI          = %ld\n\r", CPPCLI);
    printf("Current CPP CLI       = %ld\n\r", CPPCLI_VERSION);
    printf("\n\r");

    printf("First CXX CLI         = %ld\n\r", CXXCLIPRE);
    printf("Last CXX CLI          = %ld\n\r", CXXCLI);
    printf("Current CXX CLI       = %ld\n\r", CXXCLI_VERSION);
    printf("\n\r");
```

Another example of use
```c
    printf("stdc                  = %d\n\r",  GET_C_STD());
    printf("c version             = %ld\n\r", GET_C_VERSION());
    printf("c version year        = %ld\n\r", GET_C_VERSION_YEAR());
    printf("stdc hosted           = %d\n\r",  GET_C_STD_HOSTED());
    printf("\n\r");

    printf("cpp version           = %ld\n\r", GET_CPP_VERSION());
    printf("cpp version year      = %ld\n\r", GET_CPP_VERSION_YEAR());
    printf("\n\r");

    printf("cxx version           = %ld\n\r", GET_CXX_VERSION());
    printf("cxx version year      = %ld\n\r", GET_CXX_VERSION_YEAR());
    printf("\n\r");

    printf("cpp cli version       = %ld\n\r", GET_CPPCLI_VERSION());
    printf("cpp cli version year  = %ld\n\r", GET_CPPCLI_VERSION_YEAR());
    printf("\n\r");

    printf("cxx cli version       = %ld\n\r", GET_CXXCLI_VERSION());
    printf("cxx cli version year  = %ld\n\r", GET_CXXCLI_VERSION_YEAR());
    printf("\n\r");
```

Another example of use C
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

Another example of use C++
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
 
    or
 
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

Another example of use C++ CLI
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

Another example of use EC++
```c
    #if defined(ECPP)
        ...
        ECPP code
        ...
    #endif

    or
 
    #if defined(ECXX)
        ...
        ECPP code
        ...
    #endif
```

# Updates
2025 10 29 Fixed error when detecting __cplusplus for Turbo C++<br>
2025 10 29 NOC, NOCPP/NOCXX, NOCPPCLI/NOCXXCLI defines added<br>
<br>
