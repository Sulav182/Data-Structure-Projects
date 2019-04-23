#ifndef ____Linked_List_H____
#define ____Linked_List_H____

#include "stdheader.h"

//Structures

//element is content of a node.
typedef int element;

//node is 1 link in a linked list. 
struct _node{
  element e;
  struct _node* next;
};

typedef struct _node node_type;
typedef struct _node* node;

//linked list is a series of links tracked by the head or start of the list. 
struct _linked_list{
  node head;
};

typedef struct _linked_list stack_type;
typedef struct _linked_list* stack;

stack newStack();
void deleteStack(stack);
int isEmpty(stack);
element pop(stack);
void push(stack, element);
element peek(stack);
void display(stack);


#endif