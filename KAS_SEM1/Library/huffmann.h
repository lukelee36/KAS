/*
 * huffmann.h
 *
 *  Created on: 23. 11. 2018
 *      Author: Jan Tichy
 */

#ifndef LIBRARY_HUFFMANN_H_
#define LIBRARY_HUFFMANN_H_

//	Huffman Tree
typedef struct huff_node
{
	char c;
	unsigned freq;
	struct huff_node * left;
	struct huff_node * right;
}node_t;

node_t *tree_create(char c, unsigned freq);
void tree_delete(node_t *node);
typedef void huffmanfn(char, const unsigned int *, size_t);
void huffman_node_encodings(const node_t *node, unsigned *arr, unsigned int pos, huffmanfn fun);
unsigned int max(unsigned int a, unsigned int b);



#endif /* LIBRARY_HUFFMANN_H_ */
