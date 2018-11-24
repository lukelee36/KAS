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

//	Huffman Tree
typedef struct huff_node
{
	char c;
	unsigned freq;
	struct huff_node * left;
	struct huff_node * right;
}node_t;

void insert(node_t * tree, unsigned freq)
{
  if (tree->freq == 0)
  {
    /* insert on current (empty) position */
    tree->freq=freq;
  }
  else
  {
    if (freq < tree->freq)
    {
      /* insert left */
      if (tree->left != NULL)
      {
        insert(tree->left, freq);
      }
      else
      {
        tree->left = malloc(sizeof(node_t));
        /* set freques explicitly, alternative would be calloc() */
        tree->left->freq = freq;
        tree->left->left = NULL;
        tree->left->right = NULL;
      }
    }
    else
    {
      if (freq >= tree->freq)
      {
        /* insert right */
        if (tree->right != NULL)
        {
          insert(tree->right,freq);
        }
        else
        {
          tree->right=malloc(sizeof(node_t));
          /* set freques explicitly, alternative would be calloc() */
          tree->right->freq=freq;
          tree->right->left = NULL;
          tree->right->right = NULL;
        }
      }
    }
  }
}

/* depth-first search */
void printDFS(node_t * current)
{
  /* change the code here */
  if (current == NULL)         return;   /* security measure */
  if (current->left != NULL)   printDFS(current->left);
  if (current != NULL)         printf("%d ", current->freq);
  if (current->right != NULL)  printDFS(current->right);
}

int main()
{
	node_t * frequencisData = malloc(sizeof(node_t));

	char dataString[46] = {'A', ' ', 'D', 'E', 'A', 'D', ' ', 'D', 'A', 'D', ' ', 'C', 'E', 'D', 'E', 'D',' ','B','A','D',' ','B','A','B','E',' ','A',' ','B','E','A','D','E','D',' ','A','B','A','C','A',' ','B','E','D',};

	int j;

	frequencisData->freq = 0;
	frequencisData->c = ' ';
	frequencisData->left = NULL;
	frequencisData->right = NULL;

	for (j = 0; j < sizeof(dataString); ++j) {
		if (dataString[j]<=127) {
			insert(frequencisData, dataString[j]);
		}
		else
		{
			insert(frequencisData, '_');
		}
	}
//	insert(frequencisData,5);
//	insert(frequencisData,8);
//	insert(frequencisData,4);
//	insert(frequencisData,3);
//	insert(frequencisData,'G');
//	insert(frequencisData,20);
//	insert(frequencisData,3);
//	insert(frequencisData,100);

	printDFS(frequencisData);
	printf("\n");
	return 0;
}


