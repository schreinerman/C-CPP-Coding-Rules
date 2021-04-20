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
 **\file mymodule.swift
 **
 ** This is my module
 ** A detailed description is available at
 ** @link MyModuleGroup file description @endlink
 **
 ** History:
 ** - 2021-4-20  1.00  Joe
 *******************************************************************************
 */

import Foundation

protocol MyModuleDelegate: class {
  
}

class MyModule:NSObject
{
    weak var delegate: MyModuleDelegate?
  
    override required init()
    {
        super.init()
        didLoaded()
    }
    
    func didLoaded()
    {
        
    }
}
