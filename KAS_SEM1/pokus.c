/*
 * pokus.c
 *
 *  Created on: 24. 11. 2018
 *      Author: lukelee36
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokus.h"

int char_search(char letters[], char s_char, int size)
{
	int count = 0;
	char *found;

	for(; (found = strchr(letters, s_char)) != NULL; letters = found + 1)
			count++;

	return count;
}

void char_insert(letter * letter_array, char c_char, unsigned freq)
{
	//kontrola jestli je struktura prazdna
	if(letter_array->freq == 0)
	{
		letter_array->letter = c_char;
		letter_array->freq = freq;
	}
	else
	{
		if(letter_array->next != NULL)
		{
			char_insert(letter_array->next, c_char, freq);
		}
		else
		{
			letter_array->next = malloc(sizeof(letter));
			letter_array->next->freq = freq;
			letter_array->next->letter = c_char;
			letter_array->next->next = NULL;
		}


	}
}

void char_print(letter * letter_array)
{
	if (letter_array == NULL) 		return;
	if (letter_array->next != NULL) char_print(letter_array->next);
	if (letter_array =! NULL)		printf("%c : %d\n", letter_array->letter, (int)letter_array->freq);
}

void char_count(char string[], int count[])
{
	int c = 0;

	while(string[c] != '\0')
	{
		if (string[c] >= 'a' && string[c] <='Z')
		{
			count[string[c] -'a']++;
		}
		c++;
	}
}

void pokus(void)
{
	//dynamicka alokace
	letter * letter_array = malloc(sizeof(letter));
	letter_array ->next =  NULL;
	letter_array ->freq = 0;
	char *p_char;

	int count[26] = {0};
	int t = 0;

	char c;
	int freq = 0;
//	int p = 0;
	int i = 0;
//	int j = 0;


	char dataString[] = {'a', ' ', 'd', 'e', 'a', 'd', ' ', 'D', 'A', 'D', ' ', 'C', 'E', 'D', 'E', 'D',' ','A',' ','B','A','D',' ','B','A','B','E',' ','A',' ','B','E','A','D','E','D',' ','A','B','A','C','A',' ','B','E','D' , '\0'};

	//p=char_search(dataString, 'A',strlen(dataString) );
	//printf("(A) je v retezci %d",p);
	//read string funcion

	char_count(dataString,count );
	for (t = 0 ; t < 26 ; t++)
		printf("%c \t  %d\n", t + 'a', count[t]);

//	for(i; i<sizeof(dataString);i++)
//	{
//
//	    c = dataString[i];
//	    freq = char_search(dataString, c ,strlen(dataString)); //prohleda retezec
//

//	    for (j = 0; j < t; ++j) {
//	    	if(letter_array[j]->letter == c)
//	    	{
//	    		p = 0;
//	    		printf("znak byl ve strukture nalezen\n");
//	    	}
//	    	else
//	    	{
//	    		p = 1;
////	    		printf("znak nebyl ve strukture nalezen\n");
//	    	}
//		}
//	    p_char = use_letter;

//	    if(char_search(p_char, c, sizeof(use_letter)) == 0)
//	    {
//
//	    	char_insert(letter_array, c, freq);
//
//	    	p_char = c;
////	    	letter_array = letter_array->next;
//	    	printf("(%c) bylo zapsano do structury s freq: %d\n",c,freq);
//
//	    }
//	    else
//	    {
//	    	printf("znak uz ve strukture je\n");
//	    }


	   // printf("(%c) je v retezci %d\n",c,p);
//	}
//	char_print(letter_array);
	//print all
//	for(p; p<strlen(letter_array); p++)
//	{
//	    printf("char %c and frequecis %d \n", letter_array[p].letter, letter_array[p].freq);
//	}

}
