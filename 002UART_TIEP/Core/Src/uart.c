/*
 * uart.c
 *
 *  Created on: Mar 29, 2022
 *      Author: ADMIN
 */

#include "uart.h"
#include "gettemperature.h"

#define MAX_DATA_UART 100

extern UART_HandleTypeDef huart2;  // cách 1 là dùng extern

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
		char *argv[10];  // tao 10 con tro
		uint8_t arg_num =0;

		char * pch;
		pch = strtok((char *)uart_buff," ");
		while(pch != NULL)
		{
			argv[arg_num]  = pch;  // cho toi pch
			pch = strtok(NULL," ");
			arg_num ++;
		}

		if(strcmp(argv[0],"gettemp") == 0)  // so sanhs chuooix bawngf nhau
		{
			gettemperature(argv, arg_num);
		}
		else if(strcmp(argv[0],"setTempMax") == 0)
		{

		}
		else if(strcmp(argv[0],"setTempMin") == 0)
		{

		}

//		HAL_UART_Transmit(&huart2,buff, strlen((char*)buff), 100);
//		HAL_UART_Transmit(&huart2,uart_buff, uart_len, 100);

		uart_len =0;
		uart_flag =0;
	}
}
void uart_init()
{
}


