// Sulav Poudyal
// CS2413
// 3/1/2016
// This file accepts input and sorts them according to quicksort or mergesort function.

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "doubly.h"
#include "sort.h"

int main(int argc, char ** argv)
{


	int a,b,c;

	char command[100];

	while(scanf("%d",&a)>0)
	{


		DLL D = (DLL) create();

		for(b=1;b<=a;b++)
		{
			scanf("%d",&c);
			add(D,c);
		}
		display(D);

		scanf("%s",command);

		if(strcmp(command, "mergesort") == 0){
			merge_sort(D);
			display(D);
		} else if (strcmp(command,"quicksort") == 0){
			quick_sort(D);
			display(D);
		}



		destroy(D);
	}
	return 0;
}







