/*
 * flashTho.c
 *
 *  Created on: May 4, 2022
 *      Author: ADMIN
 */

// f103 thôi
#include "flashTho.h"
void flash_unlock()
{
	HAL_FLASH_Unlock();
}
void flash_lock()
{
	HAL_FLASH_Lock();
}

void flash_erease(uint32_t addr)
{
	FLASH_EraseInitTypeDef eraseInit;
	eraseInit.PageAddress = addr;
	eraseInit.NbPages = 1;
	eraseInit.TypeErase = FLASH_TYPEERASE_PAGES;
	uint32_t PageError;
	HAL_FLASHEx_Erase(&eraseInit,&PageError);
}
// uint8_t a[]= {1,2,3,4,5,6,7,8};
void flash_write_arr(uint32_t addr, uint8_t *data, uint16_t len)  // mỗi lần phải ghi 2 byte
{
	for(uint16_t i =0;i<len ;i+=2)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, addr + i, data[i] | ((uint16_t)(data[i+1] << 8)));
	}
}
void flash_read_arr(uint32_t addr, uint8_t *data, uint16_t len)
{
	for(uint16_t i =0;i<len ;i+=2)
	{
		volatile uint32_t *p = (volatile uint32_t *)(addr +i);
		uint16_t data_temp = *p;

		data[i] = data_temp;
		data[i+1] = data_temp >> 8;
	}
}



