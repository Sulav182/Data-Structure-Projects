#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "calc.h"


int main(int argc, char ** argv){
	char command[100];
	int temp;
	
	
	while(scanf("%s", command) > 0)
	{
		if(strcmp(command, "add") == 0)
		{
			scanf("%d", &temp);
				add(temp);
		} 
		else if(strcmp(command, "subtract") == 0)
		{
			scanf("%d", &temp);
			subtract(temp);
		} 
		else if(strcmp(command, "multiply") == 0)
		{
			scanf("%d", &temp);
			multiply(temp);
		}
		
		else if(strcmp(command, "divide") == 0)
		{
			scanf("%d", &temp);
			divide(temp);
		}
		
		else if(strcmp(command, "mod") == 0)
		{
			scanf("%d", &temp);
			mod(temp);
		}
		else if(strcmp(command, "clear") == 0)
		{
			clear();
        } 	
	}
	
		return 0;
}