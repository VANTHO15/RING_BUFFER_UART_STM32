/*
 * uart_ring_buffer.h
 *
 *  Created on: Mar 31, 2022
 *      Author: ADMIN
 */

#ifndef INC_UART_RING_BUFFER_H_
#define INC_UART_RING_BUFFER_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>
#include "Ringbuffer.h"

void receive_rx(uint8_t data_rx);
void uart_init(void);
uint16_t uart_available();
uint8_t uart_read(void);

#endif /* INC_UART_RING_BUFFER_H_ */
