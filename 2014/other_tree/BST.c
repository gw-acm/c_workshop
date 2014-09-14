/*
*
* This was adapted from http://www.cse.unsw.edu.au/~cs1911/14s1/lec/bridging_course/BST.pdf
* I claim no ownership over the code written below.
*
*
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct tnode Node;
typedef struct tree Tree;

/* Function Prototypes */
Node * makeNode(int data); //Create a new node
Node * findNode( int data, Node *root); //Locates a node 
Node * findNode_recurse(int data, Node *root);//Locates node recursively
Node * insertNode(Node *new_node, Node *root); //inserts a node
Node * insertNode_recurse(Node *new_node, Node *root); //inserts node recursively
void printTree(Node * root); //prints the tree
void freeTree(Node *root); //frees the tree memory
int treeSize(Node *root); //Prints number of items
int treeHeight(Node *root); // Gets height


/* Struct to hold the tree */
struct tree{
	Node *root;
};

/* Struct to hold the nodes*/
struct tnode{
	int data;
	Node *left;
	Node *right;
};

/*
* Create a new Node with specified data value.
*/
Node * makeNode( int data )
{
	Node *new_node = (Node *)malloc( sizeof(Node));

	if(new_node == NULL){
		fprintf(stderr, "Error: memory allocation failed.\n");
		exit(1);
	}
	new_node -> data = data;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
}

/*
* Search tree to find a node with specified data value
*/
Node * findNode( int data, Node *root)
{
	Node *node = root; //start at the root

	//keep searching until data found, or exit from tree
	while(( node != NULL)&&(node->data != data)){
		if(data < node->data)
			node = node->left; //branch left or right depending on value
		else
			node = node-> right;
	}
	return (node);
}

/*
*  RECURSIVE
*Search tree to find a node with specified data value, and return 
* a pointer to this node. If no such node exists, return NULL.
*/
Node * findNode_recurse( int data, Node *root)
{
	if((root == NULL) || (root->data = data)){
		return root; //found node, or exited tree
	}
	else if(data < root-> data){ //search left subtree
		return findNode_recurse(data,root-> left);
	}
	else { //search right subtree
		return findNode_recurse(data, root->right);
	}
}

/*
* Insert a node into the tree
*/
Node * insertNode(Node *new_node, Node *root)
{
	Node *child = root, *parent = NULL;
	while(child != NULL){ //Find parent for new node
		parent = child; 
		if(new_node -> data < parent-> data)
			child = parent->left;
		else
			child = parent -> right;

	}
	if(parent == NULL) //tree was empty
		root = new_node;
	else if (new_node-> data < parent-> data)
		parent-> left = new_node; //insert to the left
	else
		parent->right = new_node; //insert to the right
	return root;
}

/*
* RECURSIVE
* Insert a node into the tree.
*/
Node * insertNode_recurse(Node *new_node, Node *root)
{
	if(root == NULL){ //we have reached the insertion point
		root = new_node;
	}
	else if(new_node->data < root->data){
		//insert new node into and update left subtree
		root->left = insertNode_recurse(new_node,root->left);
	}
	else{//insert new node into and update right subtree
		root->right = insertNode_recurse(new_node,root->right);
	}
	return root;
}

/*
* Print all items of the tree in order
*/
void printTree(Node *root)
{
	if(root != NULL){
		printTree(root->left); // recursively print smaller items
		printf("%d ",root->data); // print current item
		printTree(root->right); //print larger items
	}
}

/*
* Recursivelt free all the items from a Binary Tree
*/
void freeTree(Node *root)
{
	if(root!=NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

/*
* Compute the size of a Binary Tree
*/
int treeSize(Node *root)
{
	if(root == NULL){
		return 0;
	}
	else{
		return (1+treeSize(root->left)+ treeSize(root->right));
	}
}


/*
* Compute the height of a tree
*/
int treeHeight( Node *root)
{
	int leftHeight, rightHeight;
	if(root == NULL){
		return 0;
	}
	else{
		leftHeight = treeHeight(root->left);
		rightHeight = treeHeight(root->right);
		if(leftHeight > rightHeight)
			return 1+leftHeight;
		else
			return 1+rightHeight;
	}
}