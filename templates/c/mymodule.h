/**
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

/**
 *******************************************************************************
 **\file mymodule.c
 **
 ** This is my module
 ** A detailed description is available at
 ** @link MyModuleGroup file description @endlink
 **
 ** History:
 ** - 2021-4-20  1.00  Joe
 *******************************************************************************
 */

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

