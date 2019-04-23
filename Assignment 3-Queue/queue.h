#ifndef ____Doubly_Linked_List_H____
#define ____Doubly_Linked_List_H____

#include "stdheader.h"

//Structures

//element is content of a node.
typedef int element;

//node is 1 link in a linked list. 
struct _node{
  element e;
  struct _node* next;
  struct _noce* prev;
};

typedef struct _node node_type;
typedef struct _node* node;

//Double linked list is a series of links tracked by the head and tail to the start and end of the list. 
struct _double_linked_list{
  node head;
  node tail;
};

typedef struct _double_linked_list queue_type;
typedef struct _double_linked_list* queue;

queue createQueue();
void destroyQueue(queue);
void enqueue(queue,element);
element dequeue(queue);
element peek(queue);



#endif