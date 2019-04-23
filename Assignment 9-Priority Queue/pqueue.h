#ifndef _Pqueue
#define _Pqueue



#include"stdheader.h"


struct _element{
	char first[100];
	char second[100];
};
typedef struct _element element;

struct handle
{
	int i;
};
typedef struct handle Handle;
struct _pEntry
{
	element e;
	int priority;
	Handle *handle;
};
typedef struct _pEntry pEntry;
struct _pQueue
{
	pEntry *entries;
	int size;
	int num;
	int nextSize;
};
typedef struct _pQueue pqueue;
void resize(pqueue* q);
void downheap(pqueue* q, int i);
void update(pqueue* q,Handle* h,int p);
int compare(int l,int r);
void upheap(pqueue* q,int i);
void swap(pqueue* q, int i, int j);
int isEmpty(pqueue* q);
Handle *enqueue(pqueue* q, element e, int p);
pqueue* createQueue();
element dequeue(pqueue* q);

#endif