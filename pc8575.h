// @File		PCF8575.H		 		
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
#ifndef PCF8575_H_
#define PCF8575_H_

// SLAVE, MASTER ADDRESS
#define PCF8575_SLA_W 0x40
#define PCF8575_SLA_R 0x41

void PCF8575_Write(unsigned short byte)
{
    Wire_Start();
    Wire_Write(PCF8575_SLA_W);
    Wire_Write((byte & 0xFF));
    Wire_Write((byte >> 8) & 0xFF);    
    Wire_Stop();	
}

unsigned short PCF8575_Read()
{
    unsigned char lsb = 0x00;
    unsigned char msb = 0x00;
    
    Wire_Start();
    Wire_Write(PCF8575_SLA_W);
    Wire_Start();
    Wire_Write(PCF8575_SLA_R);
    msb = Wire_Ack();
    lsb = Wire_Nack();
    Wire_Stop();	
    
    return ( (msb << 8) | lsb );
}

#endif
