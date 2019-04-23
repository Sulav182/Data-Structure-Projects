/*
Sulav Poudyal
CS 2413-001
Project 2
*/



#include"graph.h"
#include"pqueue.h"
void sortVertex(graph* g);
void swap(adjlist* a,adjlist* b);
void swapInt(int *a,int* b);
void sortEdge(graph* g, adjlist* vertex);
node* insertSort(node* head,node* newNode);
adjlist* insertSortVertex(adjlist* curr,adjlist* next);

//Function to create graph

graph* createGraph()
{
	int i=0;
	graph *g = (graph*)malloc(sizeof(graph));

	g->numVertices=0;
	g->vertexList=(adjlist*)malloc(20*sizeof(adjlist));
	g->firstVertex=NULL;
	for(i;i<20;i++)
	{

		g->vertexList[i].head=NULL;
		strcpy(g->vertexList[i].name,"");
		g->vertexList[i].index=i;
		g->vertexList[i].numEdge=0;

		//printf("numEdge %d\n",g->vertexList[i].numEdge);
	}
	return g;
}

//Function to create a vertex
adjlist newVertex(graph* g,char *apc)
{
	int temp=g->numVertices;
	//printf("Index is %d\n",temp);


	strcpy(g->vertexList[temp].name,apc);
	g->vertexList[temp].index=temp;
	g->vertexList[temp].vcost=0;
	g->vertexList[temp].vend=0;
	g->vertexList[temp].bestEdge=NULL;
	g->vertexList[temp].nextVertex = NULL;
	g->firstVertex = insertSortVertex(g->firstVertex,&g->vertexList[temp]);

	//printf("Index is %d\n",g->vertexList[temp].index);
	g->numVertices++;
	return (g->vertexList[temp]);
}
//Function to create an edge
void newEdge(graph* g,int index1,int index2,int start,int end,int cost)
{


	//printf("Inside  newEdge\n");
	node* edge = (node*)malloc(sizeof(node));
	//printf("After malloc\n");

	//printf("Inside edge 2\n");
	edge->start=start;
	edge->end=end;
	edge->cost=cost;
	edge->src_vertex=index1;
	edge->dest_vertex=index2;
	//printf("numEdge %d\n",g->vertexList[index1].numEdge);
	g->vertexList[index1].numEdge++;
	//printf("numEdge %d\n",g->vertexList[index1].numEdge);
	//printf("Inside edge 3\n");
	g->vertexList[index1].head = insertSort(g->vertexList[index1].head,edge);

}
//Function to get the vertex from the airport code
adjlist getVertex(graph* g, char* apc)
{
	int i=0;
	for(i;i<g->numVertices;i++)
	{
		if(strcmp(g->vertexList[i].name,apc)==0)
			return (g->vertexList[i]);
	}
	return;
}
//Function to get the destination vertex from the edge
adjlist* getTarget(graph* g, node *e)
{
	return (&g->vertexList[(e->dest_vertex)]);
}
//Function to get the source vertex from the edge
adjlist* getSource(graph *g,node* e)
{
	printf("Inside getSource\n");
	return (&g->vertexList[(e->src_vertex)]);
}


//Function to list all the vertices and their edges
void listAll(graph* g)
{
	int i=0;
	//adjlist temp[20];
	node *temp1;
	//printf("Start Listall with vertices %d\n", g->numVertices);
	//for(i;i<g->numVertices;i++)
	//{
	adjlist* temp = g->firstVertex;
	while(temp!=NULL)
	{
		printf("Flights From %s\n",temp->name);
		temp1=temp->head;
		while(temp1!=NULL)
		{
			printf("-- Flight to %s cost:%d start:%d end:%d\n",g->vertexList[temp1->dest_vertex].name,temp1->cost,temp1->start,temp1->end);
			temp1=temp1->next;
		}
		temp=temp->nextVertex;
	}

}
//Function to print the edges connected to the vertex
//the vertex is found by comparing the given airport name to the ones stored in the graph
void list(graph* g, char * apc)
{
	int i =0;
	int flag=0;
	adjlist temp[20];
	//printf("Start List Current\n");
	for(i;i<g->numVertices;i++)
	{
		temp[i].head=g->vertexList[i].head;
		//printf("Inside for %d\n",i);
		if(strcmp(temp[i].name,apc))
		{
	//		printf("inside if\n");
			printf("Flights From %s\n", apc);

			flag=1;
			while(temp[i].head)
			{
	//			printf("Inside while\n");
				printf("-- Flight to %s cost:%d start:%d end:%d\n", g->vertexList[temp[i].head->dest_vertex].name,temp[i].head->cost,temp[i].head->start,temp[i].head->end);
				temp[i].head=temp[i].head->next;
			}
		}

		if(flag)
			break;
	}
	//printf("Done List Current\n");


}

void swap(adjlist* a,adjlist* b)
{
	adjlist temp = *a;
	*a=*b;
	*b=temp;
}

void swapInt(int *a,int* b)
{
	printf("Inside swapInt\n");
	int temp = *a;
	printf("Inside swapInt 2\n");
	*a = *b;
	printf("Inside swapInt 3\n");
	*b = temp;
}



//Dijkstra's algorithm to find the earliest and cheapest flights

void dijkstra(graph*g ,char* ap1,char* ap2)
{
	//printf("Inside dijkstra 1\n");

	//getting the source vertex
	adjlist v = getVertex(g,ap1);
	int i=0;
	adjlist vertex[20];
	//storing the vertices of the graph in new array called vertex
	for(i;i<g->numVertices;i++)
	{
		vertex[i]=g->vertexList[i];
	}
	pqueue* q = createQueue();

	//Setting the source vertex to 0 and rest to 100000
	for(i=0;i<g->numVertices;i++)
	{
		if(strcmp(g->vertexList[i].name,v.name)==0)
		{
	//		printf("Enqueue 0\n");
			enqueue(q,g->vertexList[i].name,0);
		}
		else
		{
	//		printf("Enqueue 10000\n");
			enqueue(q,g->vertexList[i].name,100000);
		}
	}

	while(!isEmpty(q))
	{
		//Print graph
	//	int j = 0;
	//	for(j = 0; j < g->numVertices; j++){
	//		adjlist temp = g->vertexList[j];
	//		while(temp.head != NULL){
	//			printf("APC: %s cost: %d start %d end %d\n", temp.name, temp.head->cost,  temp.head->start, temp.head->end);
	//			temp.head = temp.head->next;
	//		}
	//	}
		//

	//	printf("Inside IsEmpty\n");


		char *apc=dequeue(q);
		int i=0;
		adjlist v1;
		//Getting the first vertex from the list created above
		for(i;i<g->numVertices;i++)
		{
			if(strcmp(apc,vertex[i].name)==0)
				v1=vertex[i];

		}
		//adjlist v1 = getVertex(g,apc);


		//Finding all the edges of the source vertex and seting the best edge,cost and start time
		while(v1.head!=NULL)
		{
			//printf("Inside while for edge\n");
			 adjlist* v2 = getTarget(g, v1.head);
			 for(i;i<g->numVertices;i++)
			 {
			 	if(strcmp(v2->name,vertex[i].name)==0)
			 		v2=&vertex[i];

			}
			 if(v2->vend < v1.head->start)
			 {
	//			 printf("Before comparing cost\n");
	//			 printf("v2: %d\n", v2->vcost);
	//			 printf("v1: %d\n", v1.vcost);
	//			 printf("v1.head: %d\n", v1.head->cost);
				 if(v2->vcost > v1.vcost + v1.head->cost)
				 {
	//				 printf("Inside dijkstra 2\n");
					 v2->vcost = v1.vcost + v1.head->cost;
					 v2->bestEdge = v1.head;
					 v2->vend = v1.head->end;
	//				 printf("After setting best edge with cost%d\n",v2->bestEdge->cost);
					 update(q, v2->index,v2->vcost);
				 }
			 }

			if(v2->vend > v1.head->end)
			 {
				 v2->vend = v1.head->end;
				 v2->bestEdge = v1.head;
				 update(q,v2->index,v2->vend);
			 }

		v1.head=v1.head->next;
		}
	}
}
	/*
		int i=0;
		for(i;i<g->numVertices;i++)
		{
			if(strcmp(g->vertexList[i].name,v1.name))
			{
				 node *edge= g->vertexList[i].head;

				 while(edge->next!=NULL)
				 {
					 adjlist* v2 = getTarget(g, edge);

					 if(v2->vend < edge->start)
					 {
						 if(v2->vcost > v1.vcost + edge->cost)
						 {
							 v2->vcost = v1.vcost + edge->cost;
							 v2->bestEdge = edge;
							 v2->vend = edge->end;
							 update(q, v2->index,v2->vcost);
						 }
					 }
					 edge=edge->next;
				 }
			 }
		 }
	 }


}

*/
//Recursive function to print the flight info walking the list from end to source vertex
recPrintFlight(graph* g, adjlist* dest)
{
	//printf("Inside recPrint 1\n");
	if(dest==NULL) return;

	adjlist* source=getSource(g, dest->bestEdge);
//
	recPrintFlight(g,source);


	list(g, g->vertexList[dest->bestEdge->src_vertex].name);

}



//Function to sort the edges
node* insertSort(node* head,node* newNode)
{
	if(head==NULL)
	{
		return newNode;
	}
	else if(newNode->start<newNode->start)
	{
		newNode->next=head;
		return newNode;
	}
	else
	{
		head->next = insertSort(head->next,newNode);
		return head;
	}
}
//Function to sort the vertices
adjlist* insertSortVertex(adjlist* curr,adjlist* next)
{
	if(curr==NULL)
	{
		return next;
	}
	else if(strcmp(curr->name,next->name)>0)
	{
		next->nextVertex = curr;
		return next;
	}
	else
	{
		curr->nextVertex = insertSortVertex(curr->nextVertex,next);
		return curr;
	}
}
