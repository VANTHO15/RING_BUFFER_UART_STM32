/*
 * lm35.h
 *
 *  Created on: Mar 30, 2022
 *      Author: ADMIN
 */

#ifndef INC_LM35_H_
#define INC_LM35_H_

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "string.h"

uint8_t LM35_Gettemp(uint8_t channel);

#endif /* INC_LM35_H_ */
