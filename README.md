# C CPP Coding Rules
 C/C++ Coding Rules

Files/Modules
=============

The module name is done in CammelCase. 

Example: `LcdDriver`
- Header-File: `lcddriver.h`
- C-File/CPP-File: `lcddriver.c` / `lcddriver.cpp`

Disclaimer
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

File-Information
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

Variables
=========

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
| Callback	| cbMyCallbac | callback                          |


