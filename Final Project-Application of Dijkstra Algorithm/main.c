/*
Sulav Poudyal
CS 2413-001
Project 2
*/



#include"graph.h"
#include"pqueue.h"

int main(int argc,char **argv)
{
	char command[100];
	char a[4];
	int i=0;
	graph* g =(graph*) createGraph();
	adjlist vertex1;
	adjlist vertex2;

	int start,end,cost;
	node edge;
	int count=0,flag1=0,flag2=0,flag3=0;
	while(scanf("%s", command) > 0)
	{
		if(strcmp(command, "Flight") == 0)
		{
			char apc1[4]="";
			char apc2[4]="";
			//printf("Before scanning\n");
			scanf("%s", apc1);
			//printf("APC1 %s\n",apc1);
			scanf("%s", apc2);
			//printf("APC2 %s\n",apc2);
			scanf("%d", &cost);
			scanf("%d", &start);
			scanf("%d", &end);
			//printf("After Scanning\n");
			if(g->numVertices==0)
				count=1;
			else
				count=(g->numVertices)+1;

			for(i=0;i<count;i++)
			{
				if(strcmp(g->vertexList[i].name,apc1)==0)
				{
			//		printf("Vertex1 for loop %d %s\n",i,apc1);
					vertex1=g->vertexList[i];
					break;
				}
				if(i==count-1 && strcmp(apc1,g->vertexList[i].name)!=0)
				{
			//		printf("Insering newVertex\n");
					vertex1=newVertex(g,apc1);
				}

			}

			for(i=0;i<count;i++)
			{
				if(strcmp(g->vertexList[i].name,apc2)==0)
				{
			//		printf("Vertex2 for loop %d %s\n",i,apc2);
					vertex2=g->vertexList[i];
					break;
				}
				if(i==count-1 && strcmp(apc2,g->vertexList[i].name)!=0)
				{
			//		printf("Insering newVertex 2\n");
					vertex2=newVertex(g,apc2);
				}

			}


			/*	if(strcmp(g->vertexList[i].name,apc2)==0)
				{
					//printf("Before second vertex\n");
					vertex2=getVertex(g,apc2);
					flag2=1;
				}
			}
			if(!flag1)
				vertex1=newVertex(g,apc1);
			if(!flag2)
				vertex2=newVertex(g,apc2);*/
			//printf("Before edge , index is %d\n",vertex1.index);
			//printf("vertex1index: %d   vertex2index: %d\n ", vertex1.index, vertex2.index);
			newEdge(g, vertex1.index,vertex2.index, start,end,cost);

			//printf("In main after newEdge\n");

		}

		else if(strcmp(command, "List") == 0)
		{
			scanf("%s",a);
			adjlist v=getVertex(g,a);
			if(strcmp(a,"*")==0)
			{
				if(g->numVertices==0)
					printf("Network Is Empty\n");
		//		printf("Inside listall 2\n");
				else
					listAll(g);
			}
			else if(g->numVertices==0)
				printf("Airport %s Not Found\n",a);
			else if(strcmp(v.name,a)==0)
			{
				list(g,a);
			}

		}

		else if(strcmp(command, "Cheapest") == 0)
		{
			char apc1[4], apc2[4];
			scanf("%s",apc1);
			scanf("%s",apc2);

			printf("Cheapest From:%s To:%s\n",apc1,apc2);
			//dijkstra(g,apc1,apc2);
			adjlist v = getVertex(g, apc2);

			//recPrintFlight(g,v);


		}
		else if(strcmp(command, "Earliest") == 0)
		{
			char ap1[4],ap2[4];
			scanf("%s",ap1);
			scanf("%s",ap2);
			printf("Earliest From:%s To:%s\n",ap1,ap2);
			adjlist v = getVertex(g, ap2);
			//dijkstra(g,ap1,ap2);

			//recPrintFlight(g,v);
		}


	}


return 0;
}
