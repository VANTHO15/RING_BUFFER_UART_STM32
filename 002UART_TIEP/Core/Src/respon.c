/*
 * respon.c
 *
 *  Created on: Mar 30, 2022
 *      Author: ADMIN
 */


#include "respon.h"

#include <stdarg.h>
#include <stdio.h>

static UART_HandleTypeDef *huart_print;

// printf
void respon_print(const char* str, ...)
{
	char stringArray[100];

	va_list args;
	va_start(args, str);
	vsprintf(stringArray, str, args);
	va_end(args);

	HAL_UART_Transmit(huart_print,(uint8_t *)stringArray,strlen(stringArray), 100);
}

void response_init(UART_HandleTypeDef *_huart)
{
	huart_print = _huart;
}

