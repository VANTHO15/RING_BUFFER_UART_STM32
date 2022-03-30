/*
 * lm35.c
 *
 *  Created on: Mar 30, 2022
 *      Author: ADMIN
 */

#include "lm35.h"

uint8_t LM35_Gettemp(uint8_t channel)
{
	uint8_t temp = 25.5;
	if(channel == 0)  temp= 25;
	if(channel == 1)  temp= 100;
	if(channel == 2)  temp= 28;

	return temp;
}
