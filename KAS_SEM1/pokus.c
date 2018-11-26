/*
 * pokus.c
 *
 *  Created on: 24. 11. 2018
 *      Author: lukelee36
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct letter_node
{
    char letter;
    unsigned freq;
}letter;

int main() {
	//dynamicka alokace
	letter * letter_array = malloc(sizeof(letter)*46);

	char c;
	int j, t = 0;

	char dataString[46] = {'A', ' ', 'D', 'E', 'A', 'D', ' ', 'D', 'A', 'D', ' ', 'C', 'E', 'D', 'E', 'D',' ','A',' ','B','A','D',' ','B','A','B','E',' ','A',' ','B','E','A','D','E','D',' ','A','B','A','C','A',' ','B','E','D'};

	//read string funcion
	for(int i; i<sizeof(dataString);i++)
	{
	    c = dataString[i];
	    while(letter_array[j].letter != '\0')
	    {
	        if(c == letter_array[i].letter)
	        {
	            letter_array[i].freq++;
	            t = 1;
	            break;
	        }
	        j++;
	    }

	    if(t == 0)
	    {
	        j = 0;
	        while(letter_array[j].letter != '\0')
	        {
	            j++;
	        }
	        letter_array[j].letter = c;
	        letter_array[j].freq++;
	    }
	}

	//print all
	for(int p; p<sizeof(letter_array); p++)
	{
	    printf("char %c and frequecis %d \n", letter_array[p].letter, letter_array[p].freq);
	}

	return 0;
}
