
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

int enqueue(pqueue* q, char* n, int p)
{
	if(q->num >= q->size-1)
		resize(q);
	//printf("Inside Enqueue\n");
	int index = q->num+1;
	//printf("Index set\n");
	q->num++;
	strcpy(q->entries[index].name,n);
	q->entries[index].priority = p;

	//Handle* newhandle = (Handle*)malloc(sizeof(Handle));
	//q->entries[index].handle = newhandle;
	//newhandle->i = index;
	//printf("Index %d\n",index);
	q->entries[index].i=index;
	//printf("Handle set %d\n", q->entries[index].handle);
//	printf("Enqueue of %s with priority %d\n",q->entries[index].name,q->entries[index].priority);
	upheap(q,index);
//	printf("Before returning from enqueue\n");
	return q->entries[index].i;
}



char* dequeue(pqueue* q)
{
	//printf("Inside dequeue\n");
	char *temp[4];
	//printf("Before copying the elements to temp");

	strcpy(*temp,q->entries[1].name);
	//temp->priority=q->entries[1].priority;
	//printf("Copied the characters from 1st to temp\n");
	//temp->handle = q->entries[1].handle;

	strcpy(q->entries[1].name,q->entries[q->num].name);

	//printf("Copied characters from last index to first\n");
	q->entries[1].priority = q->entries[q->num].priority;
	q->entries[1].i = q->entries[q->num].i;
	q->num--;
	//printf("Before downheap\n");
	downheap(q,1);
	return (*temp);
}

 int isEmpty(pqueue* q)
 {
	 if (q->num>0)
	 	return 0;
	 return 1;
 }

 void swapq(pqueue* q, int a, int b)
{
	//printf("Inside swap\n");
	 char temp1[4];
	 strcpy(temp1,q->entries[a].name);

	 strcpy(q->entries[a].name,q->entries[b].name);

	strcpy(q->entries[b].name,temp1);

	//printf("After copying\n");
	int p = q->entries[a].priority;
	q->entries[a].priority=q->entries[b].priority;
	q->entries[b].priority=p;
	// int k = q->entries[i].handle->i;
	int temp;
	temp=q->entries[a].i;

	//printf("Handle pointer %d",q->entries[a].handle->i);
	//printf("Handle pointer %d",q->entries[b].handle->i);

	q->entries[a].i=q->entries[b].i;
	q->entries[b].i=temp;
	//printf("After swapping the handle");
//	printf("Swapping index %d and %d\n",a,b);
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
		swapq(q,i/2,i);
		//printf("Before upheap after swap\n");
		upheap(q,i/2);
		//printf("After upheap after swap\n");
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
			swapq(q,i,2*i);

			return;
		}
	}
	if(q->entries[2*i].priority>q->entries[2*i+1].priority)
	{
		if(q->entries[2*i].priority>q->entries[i].priority)
		{
			swapq(q,i,2*i);
			downheap(q,2*i);
		}

	}
	else if(q->entries[2*i+1].priority>q->entries[2*i].priority)
	{
		if(q->entries[2*i+1].priority>q->entries[i].priority)
		{
			swapq(q,i,2*i+1);
			downheap(q,2*i+1);
		}
	}
}


void update(pqueue* q,int h,int p)
{
//	printf("Inside update 1 \n");
	int index = h;
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
//	printf("Resized Array To %d\n",q->size);
	return;
}

void display(pqueue* q)
{
//	printf("Inside display function\n");
	int j = 1;
//	printf("Size %d\n",q->size);
//	printf("Number of entries %d\n",q->num);
//	printf("Next size %d\n",q->nextSize);

	for(j;j<=q->num;j++)
	{
	//printf("Inside display function's loop\n");
//	printf("%s and priority %d\n",q->entries[j].name,q->entries[j].priority);
	}

}


