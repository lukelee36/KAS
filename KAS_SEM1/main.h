/*
 * main.h
 *
 *  Created on: 22. 11. 2018
 *      Author: lukelee36
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>

typedef struct duoArray
{
	int c;
	unsigned freq;
	struct duoArray * next;
}arr_t;

//	funkce pro ohodnoceni stringu
arr_t *setArr(int c, unsigned freq);
void setFrequency(int array, size_t array_size);
//int freqString(void *data[]);


#endif /* MAIN_H_ */
