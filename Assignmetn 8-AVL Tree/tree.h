//Sulav Poudyal
//Data Structures
//Assignment 8 : 4/4/2016

#ifndef _TREE
#define _TREE

#include "stdheader.h"

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	unsigned int height;
}node;



typedef struct tree{
	node* root;
}tree;





void insert(tree* t, int data);
node* recAVLInsert(node *root, int n);
void preOrder(node* n);
void inOrder(node* n);
int recCalculate(node* n);
//void removeNode(tree* t, node* n);
//node* recRemove(node* root,node* node);
node* Delete(node *n, int d,int *a);
node* findMin(node* n);
void postOrder(node* n);
void removeNode(node* n, int d);
void deleteTree(node** n);
void clear( node* n );
int search(node* n, int d);
node* recAVLremove(node*root, int e, int* a);
node *removeLargestNode(node *root,node** largest);
node* getLeastNode(node* n, node** least);

node *rebalance(node*n);
void recHeight(node* n);
int height(node *n);
node *rotateLeft(node*n);
node *rotateRight(node*n);
#endif