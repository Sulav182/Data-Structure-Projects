#include "stack.h"
#include<stdio.h>

stack newStack()
{
	stack s = (stack) malloc(sizeof(stack_type);
	s->head = NULL;
	return s;
 }

 void deleteStack(stack s)
 {
	while (s->head)
	{
		temp=s->head;
		s->head=s->head->next;
		free(temp);
	}
	free(s);
}

 int isEmpty(stack s)
 {
	if (s->head=NULL)
		return 1;
	else
		return 0;
 }

 element pop(stack s)
 {
	node temp= s->head->next;
	element e = s->head->e;
	free (s->head);
	s->head=temp;
	return e;
 }

 void push(stack s, element e)
 {
	node n=(node) malloc(sizeof(node->type));
	n->e=e;
	n->next=s->head;
	s->head=n;
 }

 element peek(stack s)
 {
	 if (isEmpty(s));
	 	printf("Is Empty/n");
	 else
	 	return s->head->e;
 }

 void display (stack s)
 {
	 printf("Display:\n")
	 while (s!=NULL)
	 {
		 printf("%d /n", s->head->e);
		 s=s->head;
	 }

 }




