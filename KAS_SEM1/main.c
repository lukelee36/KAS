/*
 * main.c
 *
 *  Created on: 22. 11. 2018
 *      Author: lukelee36
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//	This structure is for struct array
struct pole
{
	char c;
	int value;
};

struct pole freqString(void *data[])
{
	struct pole frequencisData[];
	int i,j;

	for (i = 0; i < sizeof(data); ++i)
	{
		for (j = 0; j < sizeof(frequencisData); ++j)
		{
			//	TODO v pøípadì že se data rovnaji pøipíše se k value jednièka, pokud ne, tak se vytvoøí nový znak v poli struktur
			if (data[i] == frequencisData[j])
			{
				frequencisData[j].value++;
				break;
			}
			else
			{

			}
		}
		frequencisData[var].c = data[var];
		frequencisData[var].value++;
	}
	return frequencisData;
}

int main()
{
	char myDataString[7] = {'a' , 'b', 'c', 'e', 'w', 'e', '\0'};

	for (int var = 0;  var < sizeof(myDataString); ++var) {
		printf();
	}
//	printf("Hello World");
	return 0;
}


