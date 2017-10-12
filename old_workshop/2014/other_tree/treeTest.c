#include <stdio.h>
#include <stdlib.h>
#include "BST.c"
int main()
{
	Tree *test1 = (Tree*)malloc(sizeof(Tree*));
	test1->root = makeNode(4);
	printTree(test1->root);
	printf("\n");
	insertNode(makeNode(5),test1->root);
	insertNode(makeNode(1),test1->root);
	insertNode(makeNode(8),test1->root);
	insertNode(makeNode(17),test1->root);
	insertNode(makeNode(6),test1->root);
	insertNode(makeNode(0),test1->root);
	insertNode(makeNode(23),test1->root);
	insertNode(makeNode(3),test1->root);
	insertNode(makeNode(7),test1->root);
	insertNode(makeNode(25),test1->root);
	printTree(test1->root);
	printf("\n");
	freeTree(test1->root);
	return 0;
}