/*
 * gettemperature.h
 *
 *  Created on: Mar 30, 2022
 *      Author: ADMIN
 */

#ifndef INC_GETTEMPERATURE_H_
#define INC_GETTEMPERATURE_H_

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "string.h"
#include "lm35.h"

void gettemperature(char **argv, uint8_t arg_num);

#endif /* INC_GETTEMPERATURE_H_ */
