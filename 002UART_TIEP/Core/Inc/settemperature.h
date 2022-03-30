/*
 * settemperature.h
 *
 *  Created on: Mar 30, 2022
 *      Author: ADMIN
 */

#ifndef INC_SETTEMPERATURE_H_
#define INC_SETTEMPERATURE_H_

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "string.h"

void settemperatureMax(char **argv, uint8_t arg_num);
void settemperatureMin(char **argv, uint8_t arg_num);

#endif /* INC_SETTEMPERATURE_H_ */
