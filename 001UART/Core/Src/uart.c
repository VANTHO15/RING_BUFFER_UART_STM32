/*
 * uart.c
 *
 *  Created on: Mar 29, 2022
 *      Author: ADMIN
 */

#include "uart.h"

#define MAX_DATA_UART 100

extern UART_HandleTypeDef huart2;  // cách 1 là dùng extern
UART_HandleTypeDef *huart1;			// cách 2 là truyền con trỏ thông qua init

static uint8_t uart_buff[MAX_DATA_UART];
static uint8_t uart_len;
uint8_t uart_flag =0;
void receive_data(uint8_t data_rx)
{
	if(data_rx == '\n')  // nhận xong
	{
		uart_buff[uart_len++] = '\0';  // kết thúc chuỗi
		uart_flag = 1;
	}
	else  // nhận tiếp
	{
		uart_buff[uart_len ++] = data_rx;
	}
}
void uart_handle()
{
	if(uart_flag == 1)
	{
		uint8_t buff[]="data van tho\n";

		HAL_UART_Transmit(&huart2,buff, strlen((char*)buff), 100);
		HAL_UART_Transmit(&huart2,uart_buff, uart_len, 100);

		uart_len =0;
		uart_flag =0;
	}
}
void uart_init(UART_HandleTypeDef *_huart1)
{
	huart1 = _huart1;
}

