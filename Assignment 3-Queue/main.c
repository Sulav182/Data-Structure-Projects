/*
Sulav Poudyal
CS 2413-001
Assignment 2
This file includes the header stack.h and stdheader.h.
It accepts the input from the command line or from other source and performs different functions.
*/



#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "queue.h"
#include "stdheader.h"


int main(int argc, char ** argv)
{
	char command[100];
	int temp1,i;
	int temp2;
	queue q = createQueue();



	while(scanf("%s", command) > 0)
	{
		if(strcmp(command, "enqueue") == 0)
		{
			scanf("%d", &temp1);
			scanf("%d", &temp2);
			
			for(i=temp1;i<=temp2;i++)
			{
				enqueue(i);
				printf("Enqueued %d\n",i);
			}
				
		}
		else if(strcmp(command, "dequeue") == 0)
		{
			if (q->head==NULL)
			{
				printf("Stack Is Empty\n");
			}
			else
			{

				temp=dequeue(q);
				printf("Dequeued %d\n",temp);
			}
		}
		else if(strcmp(command, "peek") == 0)
		{
			if (q->head==NULL)
			{
				printf("Queue Is Empty\n");
			}
			else
			{
				temp=peek(q);
				printf("Peeked %d\n",temp);
			}
		}

		else if(strcmp(command, "display") == 0)
		{
			if (q->tail==NULL)
			{
				printf("Queue Is Empty\n");
			}
			else
			{
				display(q);
			}
		}
		else if(strcmp(command, "delete") == 0)
		{
			deleteStack(s);
		}


	}

		return 0;
}