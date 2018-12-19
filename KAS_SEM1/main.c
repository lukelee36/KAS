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
#include "Library/heapSort.h"

//	Huffman Tree
typedef struct huff_node
{
	char c;
	unsigned freq;
	struct huff_node * left;
	struct huff_node * right;
}node_t;

typedef struct duoArray
{
	char c;
	unsigned freq;
	struct duoArray * next;
}arr_t;

void setFrequency(int array, size_t array_size)
{
	arr_t * frequencisData = malloc(sizeof(arr_t));
	int *c = array;
	int f = 0;

	for (int i; i < array_size; i++)
	{
		for (int j; j < array_size; j++)
		{
//			FIXME najit korektni zapis pro porovnani pointeru a prvku z pole.
			if (*c == array[j])
			{
				f++;
			}
		}
		frequencisData->c = c;
		frequencisData->freq = f;
		i += f;
		f = 0;
		frequencisData = frequencisData->next;
	}


//
//	for (j = 0; j < sizeof(dataString); ++j) {
//			if (dataString[j]<=127) {
//				insert(frequencisData, dataString[j]);
//			}
//			else
//			{
//				insert(frequencisData, '_');
//			}
//		}
}

int main()
{
	// Kódováný øetìzec
	int dataString[46] = {'A', ' ', 'D', 'E', 'A', 'D', ' ', 'D', 'A', 'D', ' ', 'C', 'E', 'D', 'E', 'D',' ','A',' ','B','A','D',' ','B','A','B','E',' ','A',' ','B','E','A','D','E','D',' ','A','B','A','C','A',' ','B','E','D'};
//	int array[6] = {10, 5, 8, 6, 12, 0};
	size_t n = sizeof(dataString)/sizeof(dataString[0]);

	// Napøed øetìzec rozdìlíme na znaky a jejich èetnost, potom je seøadíme
	// Co je to MinHeap ?
	printf("KAS Semestralni prace 1: Huffman Tree\n");

	// Fukce na vypsani pole a serazeni pole od nejmensiho po nejvetsi
	printArray(dataString, n);
	heapSort(dataString,n);
	printArray(dataString, n);

	//do struktury zapiseme pocty jednotlivych cisel
	setFrequency(dataString,n);

	return 0;
}


