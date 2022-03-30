/*
 * Ringbuffer.h
 *
 *  Created on: Mar 31, 2022
 *      Author: ADMIN
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"

typedef struct
{
	uint8_t * buffer;
	uint16_t head;
	uint16_t tail;
    uint16_t maxlen;
}RingBuff;

void ring_buff_init(RingBuff *ring_buff , uint8_t *buff, uint16_t len);
int ring_buff_push(RingBuff *ring_buff, uint8_t data);
int ring_buff_pop(RingBuff *ring_buff, uint8_t *data);
uint16_t ring_buff_available(RingBuff *ring_buff);

#endif /* INC_RINGBUFFER_H_ */
