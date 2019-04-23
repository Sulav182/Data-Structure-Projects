#ifndef _proj2
#define _proj2

#include"stdheader.h"
//Structure of the edge
//src_vertex and dest_vertex are used to store the index of source vertex and destination vertex
struct _node{
	struct _node *next;
	int cost;
	int start;
	int end;
	int src_vertex;
	int dest_vertex;

};
typedef struct _node node;

//Structure of the vertex
typedef struct _adjlist{
	char name[4];
	int vcost;
	int vend;
	node* bestEdge;
	int index;
	node *head;
	struct _adjlist* nextVertex;
	int numEdge;
}adjlist;
//Structure of the graph
struct _graph{
	adjlist *vertexList;
	adjlist *firstVertex;
	int numVertices;
};

typedef struct _graph graph;
graph* createGraph();
node* insertSort(node* head,node* newNode);
void sortEdge(graph* g, adjlist* vertex);
void swapInt(int *a,int* b);
adjlist getVertex(graph* g, char* apc);
adjlist* getTarget(graph* g, node* e);
adjlist* getSource(graph *g,node* e);
adjlist newVertex(graph* g,char *name);
adjlist* insertSortVertex(adjlist* curr,adjlist* next);
void swap(adjlist* a,adjlist *b);
void newEdge(graph* g,int index1,int index2,int start,int end,int cost);
void listAll(graph* g);
void list(graph* g, char * apc);
void sortVertex(graph* g);

#endif