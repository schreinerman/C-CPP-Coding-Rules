# C/C++ Coding Rules
 
1 Files/Modules
=============

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

| type      | naming      | description                       |
|-----------|-------------|-----------------------------------|
| uint8_t   | u8Value     | byte / 8-bit unsigned variable    |
| uint16_t	| u16Value    | word / 16-bit unsigned variable   |   
| uint32_t	| u32Value    | dword / 16-bit unsigned variable  | 
| int8_t	| i8Value     | byte / 8-bit signed variable      |
| int16_t	| i16Value    | word / 16-bit signed variable     |
| int32_t	| i32Value    | dword / 16-bit signed variable    |
| boolean_t	| bMyBool     | boolean, `typedef bool boolean_t` | 
| stc_..._t	| stcMyStruct | structure, starts with stc        |
| en_..._t	| enValue     | enum, starts with en              |
| uint8_t*	| pu8Value    | pointer of uint8_t                |
| uint8_t**	| ppu8Value   | pointer of pointer of uint8_t     |
| Array		| au8Values[] | array of uint8_t                  |
| Callback	| cbMyCallback| callback                          |

2.1 Callback-Handler
--------------------

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

3 Structs
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

4 Enums
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
