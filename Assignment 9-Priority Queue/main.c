
#include "pqueue.h"



int main(int argc, char ** argv)
{
	char command[256];
	char first[256],last[256];
	element data,data1;
	int i=0,priority;
	int a=0,b=0;
	Handle *h[100];
	pqueue* q =(pqueue*) createQueue();



	while(scanf("%s", command)>0)
	{

		if(strcmp(command, "enqueue") == 0)
		{
			//printf("Before reading the data from console\n");
			scanf("%s", data.first);
			scanf("%s", data.second);
			scanf("%d", &priority);

			// memcpy(data.first,first, sizeof(first)*256);
			//  memcpy(data.second,last, sizeof(last)*256);

			// for(i=temp1;i<=temp2;i++)
			// {
				// printf("Before Enqueue function\n");

			h[i++]=enqueue(q,data,priority);

			//q->entries[i].handle->i=i;
			//i++;
			//printf("Enqueued %d\n",i);
			// }

		}
		else if(strcmp(command, "display") == 0)
		{
			//printf("Inside display\n");
			display(q);
		}
			/*if (q->head==NULL)
			{
				printf("Stack Is Empty\n");
			}
			else
			{

				temp=dequeue(q);
				printf("Dequeued %d\n",temp);
			}
		}*/
		else if(strcmp(command, "dequeue") == 0)
		{
			//printf("Inside Dequeue\n");
			if(q->num==0)
			{
				printf("Queue is Empty\n");

			}
			else
			{
				data1=dequeue(q);
				printf("Dequeue of %s %s\n",data1.first,data1.second);
			}
		}

		else if(strcmp(command, "update") == 0)
		{
			printf("Inside update in main\n");
			scanf("%d",&a);
			scanf("%d",&b);
			printf("Updating index %d with priority %d\n",a,b);
			update(q,h[a-1],b);


		}
		else
		{
			printf("Inside else: %s \n",command);
		}
		/*else if(strcmp(command, "delete") == 0)
		{
			deleteStack(s);
		}


	}*/
	}

		return 0;
}