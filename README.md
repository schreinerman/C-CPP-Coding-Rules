# C/C++ Coding Rules
 
Coding rules/styles can help improving readability, compatibility and stability. 

Following rules are one possibility to define a unique style.

A tool using these rules and providing code templates for new projects is https://github.com/schreinerman/CodeTemplateGen

In general the DOXYGEN documentation guidelines are used for documentation inside of the code.

1 Files/Modules
===============

The module name is done in CammelCase. 

Example: `MyModule`
- Header-File: `mymodule.h`
- C-File/CPP-File: `mymodule.c` / `mymodule.cpp`

1.1 Disclaimer
----------

The disclaimer is started with `/**` and starts with ` ** ` for each new line and is ending with ` */`

It is allowed after `/**` and before ` */` to add a line with `******`.

Example:
````
/*
 *******************************************************************************
 ** Created by Joe
 **
 ** Copyright © 2021 Joe. All rights reserved.
 **
 ** 1. Redistributions of source code must retain the above copyright notice,
 **    this condition and the following disclaimer.
 **
 ** This software is provided by the copyright holder and contributors "AS IS"
 ** and any warranties related to this software are DISCLAIMED.
 ** The copyright owner or contributors be NOT LIABLE for any damages caused
 ** by use of this software.
 *******************************************************************************
 */
````

1.2 File-Information
----------------

The file has to contain a file description with a short information about the file.

The complete module documentation is done in the .h file.

Example:
````
/**
 *******************************************************************************
 ** \file mymodule.c
 **
 ** This is my module
 ** A detailed description is available at
 ** @link MyModuleGroup file description @endlink
 **
 ** History:
 ** - 2021-4-20  1.00  Joe
 *******************************************************************************
 */
````

1.3 Header-File-Sections
------------------------

````
#if !defined(__MYMODULE_H__)
#define __MYMODULE_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 *******************************************************************************
 ** \defgroup MyModuleGroup This is my module
 **
 ** Provided functions of MyModule:
 **
 **
 *******************************************************************************
 */

//@{

/**
 *******************************************************************************
** \page mymodule_module_includes Required includes in main application
** \brief Following includes are required
** @code
** #include "mymodule.h"
** @endcode
**
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** (Global) Include files
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** Global pre-processor symbols/macros ('#define') 
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** Global type definitions ('typedef') 
 *******************************************************************************
 */

typedef struct stc_mymodule_handle
{
    uint8_t u8Dummy;
} stc_mymodule_handle_t;

/**
 *******************************************************************************
 ** Global variable declarations ('extern', definition in C source)
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** Global function prototypes ('extern', definition in C source) 
 *******************************************************************************
 */


int MyModule_Init(stc_mymodule_handle_t* pstcHandle);
int MyModule_Deinit(stc_mymodule_handle_t* pstcHandle);

//@} // MyModuleGroup

#ifdef __cplusplus
}
#endif

#endif /* __MYMODULE_H__ */

/**
 *******************************************************************************
 ** EOF (not truncated)
 *******************************************************************************
 */

````

1.4 C/CPP-File-Sections
------------------------

````
#define __MYMODULE_C__

/**
 *******************************************************************************
 ** Include files
 *******************************************************************************
 */


#include <stdint.h>
#include <stdbool.h>
#include "mymodule.h"

/**
 *******************************************************************************
 ** Local pre-processor symbols/macros ('#define') 
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** Global variable definitions (declared in header file with 'extern') 
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** Local type definitions ('typedef') 
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** Local variable definitions ('static') 
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** Local function prototypes ('static') 
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** Function implementation - global ('extern') and local ('static') 
 *******************************************************************************
 */


int MyModule_Init(stc_mymodule_handle_t* pstcHandle)
{
}

int MyModule_Deinit(stc_mymodule_handle_t* pstcHandle)
{
}


/**
 *******************************************************************************
 ** EOF (not truncated)
 *******************************************************************************
 */

````



2 Variables
===========

| type      | naming      | description                        |
|-----------|-------------|------------------------------------|
| uint8_t   | u8Value     | byte / 8-bit unsigned variable     |
| uint16_t	| u16Value    | word / 16-bit unsigned variable    |   
| uint32_t	| u32Value    | dword / 32-bit unsigned variable   | 
| int8_t	| i8Value     | byte / 8-bit signed variable       |
| int16_t	| i16Value    | word / 16-bit signed variable      |
| int32_t	| i32Value    | dword / 32-bit signed variable     |
| float32_t | f32Value    | float, `typedef float float32_t;`  |
| float32_t | f64Value    | double, `typedef double float64_t;`|
| int    	| iValue      | signed variable, arch dependend    |
| boolean_t	| bMyBool     | boolean, `typedef bool boolean_t;` | 
| stc_..._t	| stcMyStruct | structure, starts with stc         |
| en_..._t	| enValue     | enum, starts with en               |
| uint8_t*	| pu8Value    | pointer of uint8_t                 |
| uint8_t**	| ppu8Value   | pointer of pointer of uint8_t      |
| Array		| au8Values[] | array of uint8_t                   |
| Callback	| cbMyCallback| callback                           |

Hint: For boolean_t and float32_t/float64_t, the file `base_types.h` can be created and included for all files
````
/*
 *******************************************************************************
 ** Created by Manuel Schreiner
 **
 ** Copyright © 2021 io-expert.com. All rights reserved.
 **
 ** 1. Redistributions of source code must retain the above copyright notice,
 **    this condition and the following disclaimer.
 **
 ** This software is provided by the copyright holder and contributors "AS IS"
 ** and any warranties related to this software are DISCLAIMED.
 ** The copyright owner or contributors be NOT LIABLE for any damages caused
 ** by use of this software.
 *******************************************************************************
 */

/**
 *******************************************************************************
 ** \file base_types.h
 **
 ** This header file is defining integer, boolean and float types
 **
 ** History:
 ** - 2021-4-20  1.00  Manuel Schreiner
 *******************************************************************************
 */

#if !defined(__BASE_TYPES_H__)
    #define __BASE_TYPES_H__
    #include <stdint.h>
    #include <stdbool.h>

    #if !defined(_BOOLEAN_T)
        #define _BOOLEAN_T
        typedef bool boolean_t;
    #endif // !defined(BOOLEAN_T)

    #if !defined(_STDFLOAT) && !(!defined(__STDFLOAT_H__))
        #define __STDFLOAT_H__

        #ifdef __cplusplus

            using float32_t = float;
            using float64_t = double;
        #else
            typedef float  float32_t;
            typedef double float64_t;
        #endif // __cplusplus
    #endif // !defined(_STDFLOAT) && !(!defined(__STDFLOAT_H__))
#endif

/**
 *******************************************************************************
 ** EOF (not truncated)
 *******************************************************************************
 */

````
3 Defines
=========

All defines shall be written in upper-case.

3.1 Immediates
--------------

Unsigned immediates should end with UL or ULL, so there are no wrong calculations using a wrong sized immediate.

Example:
````
#define    FREQ_40MHZ     40000000UL
````

3.2 Global Defines
------------------

Global defines are starting with the module name. For example:
````
#define    MYMODULE_MYDEFINE   1
````

3.3 Local Defines
-----------------

Local defines do not have any restriction in the naming.

3.4 Helper Functions
--------------------

If defining local helper functions which possibly can be already integrated globally, make sure these are not double defined

````
#if !defined ZERO_STRUCT
#define ZERO_STRUCT(x)  memset(&x,0,sizeof(x))
#endif //!defined ZERO_STRUCT
````

4 Structs
=========

Structures will be named with a `stc` as prefix followed by the module name in lower-case, seperated by `_` and the name of the struct, ended with `_t` for typedefinition.

Example:
````
typedef struct stc_mymodule_my_struct
{
    uint8_t* pu8Data;
    uint32_t u32Length;
} stc_mymodule_my_struct_t
````

Variables of the type of struct will be named with a `stc` as prefix followed by the name in CammelCase. For global variables it makes sense to add the module name in CammelCase.

Example:
````
static stc_mymodule_my_struct_t stcMyBuffer = {
                        "test", // pu8Data
                        4       // u32Length
                    };

stc_mymodule_my_struct_t stcMyModuleGlobalBuffer =  {
                        "test2", // pu8Data
                        5        // u32Length
                    };
````

5 Enums
=======

Enumerations will be named with a `en` as prefix followed by the module name in lower-case, seperated by `_` and the name of the enum, ended with `_t` for typedefinition.

Enum values are written in CammelCase and will start with the module name in CammelCase.

Example:
````
typedef struct en_mymodule_my_enum
{
    MyModuleData8Bit,
    MyModuleData16Bit,
    MyModuleData32Bit
} en_mymodule_my_enum_t
````

Variables of the type of enum will be named with a `en` as prefix followed by the name in CammelCase. For global variables it makes sense to add the module name in CammelCase.

Example:
````
static en_mymodule_my_enum_t enDataTypeA = MyModuleData8Bit;

en_mymodule_my_enum_t enDataTypeGlobal = MyModuleData32Bit;
````

6 Callback-Handler
------------------

Callback typedefinitions starting with `pfn` (pointer of function) followed by the module name in lower-case, seperated by `_` and the name of the callback, ended with `_t` for typedefinition.

Definition Example:
````
typedef int (*pfn_mymodule_callback_t)(uint8_t u8Parameter1, boolean_t bEnable);
````

Implementation Example:
````

/**
 *******************************************************************************
 ** Local type definitions ('typedef') 
 *******************************************************************************
 */

typedef int (*pfn_mymodule_callback_t)(uint8_t u8Parameter1, boolean_t bEnable);

/**
 *******************************************************************************
 ** Local variable definitions ('static') 
 *******************************************************************************
 */

/**
 * Local function prototypes ('static') of callback implementation 
 * must be set before the variable definition
 */
static int MyCallbackImplementation(uint8_t u8Parameter1, boolean_t bEnable);


pfn_mymodule_callback_t cbCallback = MyCallbackImplementation;

/**
 *******************************************************************************
 ** Function implementation - global ('extern') and local ('static') 
 *******************************************************************************
 */

static int MyCallbackImplementation(uint8_t u8Parameter1, boolean_t bEnable)
{
    ...
}

````

7 Functions
===========

7.1 Global Functions
--------------------

Global functions are starting with the module name in CammelCase, followed by `_` and the function name in CammelCase.

The implementation of the function is done in the c-file while the prototype is located in the h-file.

Example:
````
int MyModule_Init(stc_mymodule_handle_t* pstcHandle)
{
    ...
}

int MyModule_SendData(uint8_t* pu8Data, uint32_t u32Len, pfn_mymodule_callback_t cbCallback)
{
    ...
}
````

7.2 Local Functions
--------------------

Local functions don't start with module name in CammelCase, followed by `_`. It will be just the function name in CammelCase.

The implementation of the function is done in the c-file while the prototype is located in the upper c-file (prototypes section).

Example:
````
static void SendData(uint8_t* pu8Data, uint32_t u32Len)
{
    ...
}
````

8 If - else
===========

For C / C++ following instruction is always true: `if (u8Value = 5)`

The intention was to write `if (u8Value == 5)` which is only true if u8Value is 5.

To get a compile error, the variable should be on the right-hand side: `if (5 = u8Value)`

So only following construct is working: `if (5 == u8Value)`

9 Readability
=============

9.1 spaces vs. tabs
-------------------

For each functionality-layer use 4 spaces and do not use tabulators.

Example:
````
if (5 == u8Value)
{
    for(i = 0;i < 5;i++)
    {
        ...
    }
}
````

9.2 extract code
----------------

Don't use as much code as possible in one line. This results in issues during debugging.

Bad Example:
------------
````
a = 5;b = 3;
max = (a > b) ? a : b;
````

Better Example:
------------
````
u8A = 5
u8B = 3;
if (u8A > u8B)
{
    u8Max = u8A;
}
else
{
    u8Max = u8B;
}
````


