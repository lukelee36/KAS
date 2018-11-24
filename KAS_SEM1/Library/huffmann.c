/*
 * huffmann.c
 *
 *  Created on: 23. 11. 2018
 *      Author: Jan Tichy
 */

#include <stdlib.h>
#include <stdio.h>
#include "huffmann.h"
//#include <minheap.h>

#define MAX_TREE_HT 100



//	This function are going to allocate dynamic memory for Huffman tree
node_t *tree_create(char c, unsigned freq)
{
	node_t *node = malloc(sizeof(node_t));

	if(node)
	{
		node->c = c;
		node->freq = freq;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

//	This function are going to disallocate tree in memory
void tree_delete(node_t *node)
{
	if(node)
	{
		tree_delete(node->left);
		tree_delete(node->right);
		free(node);
	}
}

void tree_dump(node_t *node, unsigned indent)
{
	unsigned i;
	for (i = 0; i < indent; ++i) {
		printf(" ");
	}
	printf("%c %u\n", node->c, node->freq);
	if(node->left != NULL)
	{
		tree_dump(node->left, indent + 1);
	}
	if(node->right != NULL)
	{
		tree_dump(node->right, indent + 1);
	}
}


//	TODO tohle predelat podle sebe, at to neni moc napadne
unsigned int max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

typedef void huffmanfn(char, const unsigned int *, size_t);

void huffman_node_encodings(const node_t *node, unsigned *arr,
        unsigned int pos, huffmanfn fun)
{
    if (node->left) {
        arr[pos] = 0;
        huffman_node_encodings(node->left, arr, pos + 1, fun);
    }
    if (node->right) {
        arr[pos] = 1;
        huffman_node_encodings(node->right, arr, pos + 1, fun);
    }
    if (!(node->left || node->right)) {
        fun(node->c, arr, pos);
    }
}

//void huffman(const char *letters, const int *frequencies, size_t size, huffmanfn fun)
//{
//    minheap *heap = minheap_create();
//    unsigned int i;
//    node_t *top;
//    unsigned int *arr;
//    /* Populate the heap */
//    for (i = 0; i < size; i++) {
//        minheap_add(heap, huffman_node_create(letters[i], frequencies[i]), frequencies[i]);
//    }
//    /* Build the tree */
//    while (minheap_get_count(heap) != 1) {
//        node_t *left = minheap_remove_min(heap);
//        node_t *right = minheap_remove_min(heap);
//        top = huffman_node_create('$', left->freq + right->freq);
//        top->left = left;
//        top->right = right;
//        minheap_add(heap, top, top->freq);
//    }
//    top = minheap_remove_min(heap);
//    /* Generate the encodings */
//    arr = malloc(huffman_node_height(top) * sizeof(unsigned int));
//    huffman_node_encodings(top, arr, 0, fun);
//    /* Clean up */
//    huffman_node_delete(top);
//    free(arr);
//    minheap_delete(heap);
//}



