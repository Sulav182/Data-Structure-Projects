#include "queue.h"
#include<stdio.h>

queue createQueue()
{
queue q = (queue) malloc(sizeof(queue_type);
 q->head = NULL;
 q->tail = NULL;
 return q;
 }

 void destroyQueue(queue q)
 {
 while (q->head)
 	{
 	temp=q->head;
 	q->head=q->head->next;
 	free(temp);
 	}
 free(s);
 }



 element dequeue(queue q)
 {
	 if(q->head==q->tail)
	{
		temp3=q->head->e;
		q->head=NULL;
		q->tail=NULL;
		return temp3;
	}
	else
	{
		node temp= q->head->next;
		element e = q->head->e;
		temp->prev=NULL;
		free (q->head);
		q->head=temp;
		return e;
	}
 }

 void enqueue(queue q, element e)
 {
	node n=(node) malloc(sizeof(node->type));
	n->e=e;
	n->next=NULL;
	if(head==NULL && tail==NULL)
	{
		head=tail=n;
		return;
	}
	q->tail->next=n;
	n->prev=q->tail;
	q->tail=n;

 }

 element peek(queue q)
 {
	 return (q->tail->e);
 }

 void display (queue q)
 {
	printf("Display In Reverse\n")
	node temp=q->tail;
	while ((temp)!=NULL)
	{
		printf("%d\n", temp->e);
		temp = temp->prev;
	}
	free(temp);
 }




