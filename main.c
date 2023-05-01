// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "config.h"
#include "wire.h"
#include "pc8575.h"

void main(void)
{     
    PIC18F2520();
    
    Wire_Init();
        
    PCF8575_Write( 0X800F );
    
    while(1)
    {
        //..
    }
    
    return;
}