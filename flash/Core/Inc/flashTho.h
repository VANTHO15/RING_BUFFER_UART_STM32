/*
 * flashTho.h
 *
 *  Created on: May 4, 2022
 *      Author: ADMIN
 */

#ifndef INC_FLASHTHO_H_
#define INC_FLASHTHO_H_

#include "stm32f1xx_hal.h"
#include "stdint.h"

void flash_erease(uint32_t addr);
void flash_write_arr(uint32_t addr, uint8_t *data, uint16_t len);
void flash_read_arr(uint32_t addr, uint8_t *data, uint16_t len);
void flash_unlock(void);
void flash_lock(void);


#endif /* INC_FLASHTHO_H_ */
