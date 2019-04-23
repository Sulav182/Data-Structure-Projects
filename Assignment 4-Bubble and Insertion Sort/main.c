

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "doubly.h"
#include "sort.h"

int main(int argc, char ** argv)
{
	//DLL D = (DLL) malloc(sizeof(DLL_type));
	//D->front=NULL;
	//D->back=NULL;
	int num;
	char command[100];

	while(scanf("%s",command)>0)
	{
		if(strcmp(command, "bubblesort")
		{
			display(D);
			bubblesort(D);
		}
		else if (strcmp(command,"insertionsort")
		{
			display(D);
			insertionsort(D);
		}
		else
		{
			num=command-48;
			add(D,num);
	    }
	}

	display(D);
}







