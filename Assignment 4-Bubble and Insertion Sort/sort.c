

#include "doubly.h"
#include "sort.h"
#include<stdio.h>

void bubble_sort(DLL D)
{
	int notDone=1;
	if(D->front==NULL)
		return;

	while (notDone)
	{
		notDone=0;
		node temp = D->front;
		while (temp && temp->next)
		{
			if(compare(temp->e,temp->next->e)>0)
			{
				printf("Swapping %d %d\n", temp->e,temp->next->e);
				elememt temp_e = temp->e;
				temp->e=temp->next->e;
				temp->next->e=temp->e;
			}
			notDone=1;
			temp=temp->next;
		}
	}

	while (D->front->prev)
	{
		D->front=D->front->prev;
	}

	while (D->back->next)
	{
		D->back=D->back->next;
	}

}

void insert_sorted(DLL D, node T)
{
	node temp = D->front;

	if (D->front==NULL)
	{
		D->front=D->back=T;
		printf("Inserting %d On Empty List\n", T->e);
		return;
	}

	else if(compare(T->e,D-front->e)<0)
	{
		T->next=D->front;
		T->next->prev=T;
		D->front=T;
		printf("Inserting %d At Front Of List\n",T->e);
	}

	else if(compare(T->e, D->back->e)>0)
	{
		T->prev=D->back;
		T->prev->next=T;
		D->back=n;
		printf("Inserting %d At Back Of List\n",T->e);
	}

	else
	{
		while(compare(T->e,temp->next->e)>0)
		{
			printf("Inserting %d Between %d And %d\n",T->e, temp->e, temp->next->e);
			temp=temp->next;
			T->prev=temp;
			T->next=temp->next;
			T->prev->next=T;
			T->next->prev=T;
		}
	}
}

void insertion_sort(DLL D)
{
	DLL_type = D2;
	D2->front=NULL;
	D2->back=NULL;

	while(D2->front)
	{
		node T = D->front;
		D->front=D->front->next;
		T->next=NULL;
		T->prev=Null;
		printf("Removed %d\n",T->e);

		insert_sorted(&D2,T);
	}
	D->front=D2->front;
	D->back=D2->back;
}

void add(DLL d, element e)
 {
	node n=(node) malloc(sizeof(node_type));
	n->e=e;
	n->next=NULL;
	n->prev=NULL;
	if(d->front==NULL && d->back==NULL)
	{
		d->front=d->back=n;
		return;
	}
	n->prev=q->back;
	q->back->next=n;
	q->back=n;

 }


void display (DLL d)
 {

	 node temp=d->front;
	while ((temp)!=NULL)
	{
		printf("%d\n", temp->e);
		temp = temp->next;
	}
}
