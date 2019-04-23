//Sulav Poudyal
//Data Structures
//Assignment 7 : 3/25/2016

#ifndef _TREE
#define _TREE

#include "stdheader.h"

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;



typedef struct tree{
	node* root;
}tree;





void insertNode(tree* t, int data);
node* recInsert(node *root, node* n);
void preOrder(node* n);
void inOrder(node* n);
int recCalculate(node* n);
//void removeNode(tree* t, node* n);
//node* recRemove(node* root,node* node);
node* Delete(node *n, int d);
node* findMin(node* n);
void postOrder(node* n);
void removeNode(node* n, int d);
void deleteTree(node** n);
void clear( node* n );
int search(node* n, int d);
#endif