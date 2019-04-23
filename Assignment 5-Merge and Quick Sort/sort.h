#ifndef ____Doubly_Linked_List2_H____
#define ____Doubly_Linked_List2_H____

#include "stdheader.h"
#include "doubly.h"

DLL create();

void add(DLL d, element e);
void display (DLL d);
void destroy(DLL d);
void appendNode(DLL d, node n);
void removeNode(DLL d, node n);
void quick_sort(DLL d);
DLL merge(DLL B, DLL c, DLL A);
void merge_sort(DLL d);

#endif

