/*
 * respon.h
 *
 *  Created on: Mar 30, 2022
 *      Author: ADMIN
 */

#ifndef INC_RESPON_H_
#define INC_RESPON_H_

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "string.h"

void respon_print(const char* str, ...);
void response_init(UART_HandleTypeDef *_huart);

#endif /* INC_RESPON_H_ */
