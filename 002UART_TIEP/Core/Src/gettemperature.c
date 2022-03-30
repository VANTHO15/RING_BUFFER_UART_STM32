/*
 * gettemperature.c
 *
 *  Created on: Mar 30, 2022
 *      Author: ADMIN
 */
#include "gettemperature.h"
#include "respon.h"
#include "stdlib.h"

extern UART_HandleTypeDef huart2;  // cách 1 là dùng extern

void gettemperature(char **argv, uint8_t arg_num)
{
	if(arg_num <2)
	{
		respon_print("don't enough arg, arg = %d \n", arg_num);
		return;
	}
	if(arg_num >= 2)
	{
		respon_print("too much enough arg, arg = %d \n", arg_num);
	}

	uint8_t channel =atoi( argv[1]);
	respon_print("temperature = %d \n",LM35_Gettemp(channel));
}
