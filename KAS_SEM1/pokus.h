/*
 * pokus.h
 *
 *  Created on: 26. 11. 2018
 *      Author: tichy
 */

#ifndef POKUS_H_
#define POKUS_H_

typedef struct letter_node
{
    char letter;
    unsigned freq;
    struct letter_node *next;
}letter;

void pokus(void);
void char_print(letter * letter_array);
int char_search(char letters[], char s_char, int size);
void char_insert(letter * letter_array, char c_char, unsigned freq);

#endif /* POKUS_H_ */
