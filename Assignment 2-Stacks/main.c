#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stack.h"
#include "stdheader.h"


int main(int argc, char ** argv)
{
	char command[100];
	int temp;
	s = newStack();
	
	
	while(scanf("%s", command) > 0)
	{
		if(strcmp(command, "push") == 0)
		{
			scanf("%d", &temp);
				push(s,temp);
				printf("Pushed %d\n", temp);
		} 
		else if(strcmp(command, "pop") == 0)
		{
			temp=pop();
			printf("Popped %d\n",temp);
		} 
		else if(strcmp(command, "peek") == 0)
		{
			temp=peek();
			printf("Peeked %d\n",temp);
		}
		
		else if(strcmp(command, "display") == 0)
		{
			display();
		}
		
        
	}
	
		return 0;
}