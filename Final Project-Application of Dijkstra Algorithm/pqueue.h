#ifndef _Pqueue
#define _Pqueue



#include"stdheader.h"


//struct handle
//{
//	int i;
//};
//typedef struct handle Handle;
struct _pEntry
{
	char name[4];
	int priority;
	int i;
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
void update(pqueue* q,int i,int p);
int compare(int l,int r);
void upheap(pqueue* q,int i);
void swapq(pqueue* q, int i, int j);
int isEmpty(pqueue* q);
int enqueue(pqueue* q,char* n, int p);
pqueue* createQueue();
char* dequeue(pqueue* q);

#endif