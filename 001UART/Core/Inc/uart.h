/*
 * uart.h
 *
 *  Created on: Mar 29, 2022
 *      Author: ADMIN
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include "string.h"

void receive_data(uint8_t data_rx);
void uart_handle(void);
void uart_init(UART_HandleTypeDef *_huart1);

#endif /* INC_UART_H_ */
