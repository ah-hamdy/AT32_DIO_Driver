/*
 * main.c
 *
 *  Created on: Dec 31, 2016
 *      Author: Ahmed HAmdy
 */


#include "STD_TYPES.h"
#include "Macro.h"
#include "DIO.h"
#include "util/delay.h"

int main ()
{
		u8 index,Value;
		u8 second_number=0,first_number=0;

		u8 segment_1 [10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


		for (index = 0; index < 6;index ++)
		{
			Dio_vidSetDirection (0,index,0);
		}

		for (index = 0;index < 8;index ++)
		{
			Dio_vidSetDirection (2,index,1);
			Dio_vidSetDirection (3,index,1);
		}

			Dio_vidSetPortValue (0,0x3F);


		while (1)
		{
			Value = Dio_u8GetPortValue (0);

			/*var_2 = segment [value];*/

			if (Value < 64)

			{
			second_number = Value / 10;
			first_number = Value % 10;

			Dio_vidSetPortValue (3,~(segment_1 [second_number]));
			Dio_vidSetPortValue (2,~(segment_1 [first_number]));
			}
		}




	return 0;
}
