// Sulav Poudyal
// CS2413
// 3/1/2016
// This file contains the definition of all the major functions in this program.
//

#include "doubly.h"
#include "sort.h"

DLL create()
{
	DLL d =  (DLL) malloc(sizeof(DLL_type));
	d->front = NULL;
	d->back = NULL;
	d->size=0;
	return d;
 }


void add(DLL d, element e)
 {

	 node n= (node)malloc(sizeof(node_type));
	 n->e=e;

	 if(d->front==NULL && d->back==NULL)
	 {
		 d->front=d->back=n;
		 d->front->prev = NULL;
         d->back->next = NULL;
		 d->size++;
		 return;
	 }
	 n->prev=d->back;
	 d->back->next=n;
	 d->back=n;
	 d->back->next = NULL;
	 d->size++;
 }


void display (DLL d)
 {

	node temp=d->front;
	while ((temp)!=NULL)
	{
		printf("%d ", temp->e);
		temp = temp->next;
	}
	printf("\n");
}


void destroy(DLL d)
 {
	while (d->front)
	{
		node temp=d->front;
		d->front=d->front->next;
		free(temp);
	}
	free(d);
 }

 void appendNode(DLL d, node n)
 {
	 if(d->front==NULL)
	 {
		 d->front=d->back=n;
	 }
	 else
	 {
		 d->back->next=n;
		 n->prev=d->back;
		 d->back=n;
	 }
	 d->size++;
 }

 void removeNode(DLL d, node n)
 {
	 if(d->front==n)
	 {
		 d->front=d->front->next;
		 if(d->front==NULL)
		 	d->back=NULL;
		 else
		 {
			 d->front->prev=NULL;
			 n->next=NULL;

		 }

	 }
	 else if(d->back==n)
	 {
		 d->back=d->back->prev;
		 if(d->back==NULL)
		 	d->front=NULL;
		 else
		 {
			 d->back->next=NULL;
			 n->prev=NULL;
		 }
	 }
	 else
	 {
		 n->prev->next=n->next;
		 n->next->prev=n->prev;
		 n->next=n->prev=NULL;
	 }
	 d->size--;
 }

 void quick_sort(DLL d)
 {
	printf("Quick Sort, Size Of List: %d\n", d->size);
	DLL A = create();
	DLL B = create();
	if(d->size<2)
	return ;
	node n=d->front;
	removeNode(d,n);
	printf("Picked Pivot: %d\n", n->e);


	while (d->size>0)
	{
		node temp = d->front;
		removeNode(d, temp);
		if(temp->e<=n->e)
		appendNode(A,temp);
		else
		appendNode(B,temp);
	}
	quick_sort(A);
	quick_sort(B);

	if(A->front==NULL)
	{
		d->front=n;
		n->next=B->front;
		d->back=B->back;
		d->front->prev=n;
		d->size=B->size+1;
	}
	else if(B->front==NULL)
	{
		d->front = A->front;
		n->next = NULL;
		d->back = n;
		A->front->prev = NULL;
		n->prev = A->back;
		A->back->next = n;
		d->size = A->size+1;
	}
	else
	{
		d->front=A->front;
		d->back=B->back;
		A->back->next=n;
		B->front->prev=n;
		n->next=B->front;
		n->prev=A->back;

		d->size=(A->size)+(B->size)+1;

	}
	A->front = A->back=NULL;
	destroy(A);
	B->front=B->back=NULL;
	destroy(B);

	 printf("DONE: Quick Sort, Size Of List: %d\n", d->size);
}

DLL merge(DLL A, DLL B, DLL d)
{
	node temp;
	while(A->front && B->front)
	{
		node temp;
		if(A->front->e < B->front->e)
		{
			temp = A->front;
			removeNode(A,temp);
			appendNode(d,temp);

		}
		else if(A->front->e > B->front->e)
        {
		   temp = B->front;
		   removeNode(B,temp);
		   appendNode(d,temp);
        }
	}
	while(A->front != NULL)
	{
	    temp = A->front;
	    removeNode(A,temp);
        appendNode(d, temp);
	}

	while(B->front != NULL)
	{
        temp = B->front;
        removeNode(B,temp);
	    appendNode(d,temp);
	}

	A->front = A->back = NULL;
	free(A);
	B->front = B->back = NULL;
	free(B);
	return d;


}

void merge_sort(DLL d)
{


	DLL A =  create();
	DLL B =  create();
	A->front=d->front;
	node temp=d->front;

	printf("Merge Sort, Size Of List: %d\n", d->size);
	if(d->front==d->back)
		return;

	int i =0;
	for(i;i<(d->size-1)/2;i++)
	{
		temp=temp->next;
	}


	A->back=temp;
	B->front=temp->next;
	temp->next=NULL;
	B->front->prev = NULL;
	B->back = d->back;
	d->front = d->back = NULL;
	d->size = 0;

	node temp2=A->front;
	node temp3=B->front;
	int j=0,k=0;

	while(temp2!=NULL)
	{
		temp2=temp2->next;
		j++;
	}
	A->size=j;

	while(temp3!=NULL)
	{
		temp3=temp3->next;
		k++;
	}
	B->size=k;


	merge_sort(A);
	merge_sort(B);
	d=merge(A,B,d);
	printf("DONE: Merge Sort, Size Of List: %d\n", d->size);

}










