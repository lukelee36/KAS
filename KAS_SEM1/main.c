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
typedef struct node
{
	char c;
	int val;
	struct node * left;
	struct node * right;
}node_t;

void insert(node_t * tree, int val)
{
  if (tree->val == 0)
  {
    /* insert on current (empty) position */
    tree->val=val;
  }
  else
  {
    if (val < tree->val)
    {
      /* insert left */
      if (tree->left != NULL)
      {
        insert(tree->left, val);
      }
      else
      {
        tree->left = malloc(sizeof(node_t));
        /* set values explicitly, alternative would be calloc() */
        tree->left->val = val;
        tree->left->left = NULL;
        tree->left->right = NULL;
      }
    }
    else
    {
      if (val >= tree->val)
      {
        /* insert right */
        if (tree->right != NULL)
        {
          insert(tree->right,val);
        }
        else
        {
          tree->right=malloc(sizeof(node_t));
          /* set values explicitly, alternative would be calloc() */
          tree->right->val=val;
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
  if (current != NULL)         printf("%d ", current->val);
  if (current->right != NULL)  printDFS(current->right);
}

int main()
{
	node_t * frequencisData = malloc(sizeof(node_t));

	char dataString[16] = {'A', ' ', 'D', 'E', 'A', 'D', ' ', 'D', 'A', 'D', ' ', 'C', 'E', 'D', 'E', 'D'};

	int j;

	frequencisData->val = 0;
	frequencisData->c = ' ';
	frequencisData->left = NULL;
	frequencisData->right = NULL;

	for (j = 0; j < sizeof(dataString); ++j) {
		insert(frequencisData, dataString[j]);
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


