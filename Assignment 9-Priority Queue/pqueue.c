
#include"pqueue.h"
#include<stdio.h>

void downheap(pqueue* q, int i);
void upheap(pqueue* q,int i);
pqueue* createQueue()
{
	pqueue* q= (pqueue*)malloc(sizeof(pqueue));
	q->size=2;
	q->nextSize=2;
	q->num=0;
	// q->entries[0].handle->i=0;
	q->entries=(pEntry*)malloc(sizeof(pEntry)*q->size);
	return q;
}

Handle* enqueue(pqueue* q, element e, int p)
{
	if(q->num >= q->size-1)
		resize(q);
	//printf("Inside Enqueue\n");
	int index = q->num+1;
	//printf("Index set\n");
	q->num++;
	q->entries[index].e=e;
	q->entries[index].priority = p;

	Handle* newhandle = (Handle*)malloc(sizeof(Handle));
	//q->entries[index].handle = newhandle;
	newhandle->i = index;
	//printf("Index %d\n",index);
	q->entries[index].handle=newhandle;
	//printf("Handle set %d\n", q->entries[index].handle);
	printf("Enqueue of %s %s with priority %d\n",q->entries[index].e.first,q->entries[index].e.second,q->entries[index].priority);
	upheap(q,index);

	return newhandle;
}



element dequeue(pqueue* q)
{
	//printf("Inside dequeue\n");
	element temp;
	//printf("Before copying the elements to temp");
	strcpy(temp.first,q->entries[1].e.first);
	strcpy(temp.second,q->entries[1].e.second);
	//temp->priority=q->entries[1].priority;
	//printf("Copied the characters from 1st to temp\n");
	//temp->handle = q->entries[1].handle;

	strcpy(q->entries[1].e.first,q->entries[q->num].e.first);
	strcpy(q->entries[1].e.second,q->entries[q->num].e.second);
	//printf("Copied characters from last index to first\n");
	q->entries[1].priority = q->entries[q->num].priority;
	q->entries[1].handle = q->entries[q->num].handle;
	q->num--;
	//printf("Before downheap\n");
	downheap(q,1);
	return temp;
}

 int isEmpty(pqueue* q)
 {
	 if (q->num>0)
	 	return 0;
	 return 1;
 }

 void swap(pqueue* q, int a, int b)
{
	//printf("Inside swap\n");
	element temp1;
	strcpy(temp1.first,q->entries[a].e.first);
	strcpy(temp1.second,q->entries[a].e.second);
	strcpy(q->entries[a].e.first,q->entries[b].e.first);
	strcpy(q->entries[a].e.second,q->entries[b].e.second);
	strcpy(q->entries[b].e.first,temp1.first);
	strcpy(q->entries[b].e.second,temp1.second);
	//printf("After copying\n");
	int p = q->entries[a].priority;
	q->entries[a].priority=q->entries[b].priority;
	q->entries[b].priority=p;
	// int k = q->entries[i].handle->i;
	Handle *temp;
	temp=q->entries[a].handle;

	//printf("Handle pointer %d",q->entries[a].handle->i);
	//printf("Handle pointer %d",q->entries[b].handle->i);

	q->entries[a].handle=q->entries[b].handle;
	q->entries[b].handle=temp;
	//printf("After swapping the handle");
	printf("Swapping index %d and %d\n",a,b);
}

void upheap(pqueue* q,int i)
{
	//printf("Inside upheap.\n");
	if(i<=1){
	//	printf("Index is <= 1\n");
		return;
	}
	//printf("Inside upheap\n");
	if(q->entries[i].priority>q->entries[i/2].priority)
	{
	//	printf("Before Swap\n");
		swap(q,i/2,i);
	//	printf("Before upheap after swap\n");
		upheap(q,i/2);
	} else {
		//printf("Priority less than or equal to.\n");
		return;
	}
}

int compare(int l,int r)
{
	if(l<r)
		return -1;

	if(l>r)
		return 1;
	return 0;
}


void downheap(pqueue* q, int i)
{
	if(i<1 || i > q->num)
		return;
	if(i*2>q->num)
		return;
	if(2*i+1>q->num)
	{
		if (compare(q->entries[2*i].priority,q->entries[i].priority))
		{
			swap(q,i,2*i);

			return;
		}
	}
	if(q->entries[2*i].priority>q->entries[2*i+1].priority)
	{
		if(q->entries[2*i].priority>q->entries[i].priority)
		{
			swap(q,i,2*i);
			downheap(q,2*i);
		}

	}
	else if(q->entries[2*i+1].priority>q->entries[2*i].priority)
	{
		if(q->entries[2*i+1].priority>q->entries[i].priority)
		{
			swap(q,i,2*i+1);
			downheap(q,2*i+1);
		}
	}
}


void update(pqueue* q,Handle* h,int p)
{
	//printf("Inside update 1 \n");
	int index = h->i;
//	printf("Inside update 2 \n");
	int temp = q->entries[index].priority;
	q->entries[index].priority = p;
//	printf("Inside update 3 \n");
	if(q->entries[index].priority>temp)
	{
//		printf("Inside update 4 \n");
		upheap(q,index);
	}
	else
	{
//		printf("Inside update 5 \n");
		downheap(q,index);
	}
}





void resize(pqueue* q)
{
	//printf("Inside resize\n");
	pEntry* newArray =(pEntry*) malloc(sizeof(pEntry)*(q->nextSize+q->size)) ;
	int i;
	//printf("Before loop\n");
	for(i=1; i <=q->num ; i++)
	{
		newArray[i]=q->entries[i];
		//printf("Inside loop in resize\n");
	}
	//printf("After loopin resize\n");
	q->entries=newArray;
	//printf("Done setting entries to newarray\n");
	q->size=q->size + q->nextSize;

	q->nextSize = 2*q->nextSize;
	printf("Resized Array To %d\n",q->size);
	return;
}

void display(pqueue* q)
{
	printf("Inside display function\n");
	int j = 1;
	printf("Size %d\n",q->size);
	printf("Number of entries %d\n",q->num);
	printf("Next sixe %d\n",q->nextSize);

	for(j;j<=q->num;j++)
	{
		//printf("Inside display function's loop\n");
		printf("%s %s and priority %d\n",q->entries[j].e.first,q->entries[j].e.second,q->entries[j].priority);
	}

}


