// Sulav Poudyal
// CS2413
// 3/9/2016
//Main file where the various operations is performed on the input

#include "map.h"

int main(int argc, char ** argv)
{


	int a=0,b=0,c=0;
	key k;
	value v,*v1;


	char command[100];
	map *m=createMap();

	//for(a;a<=m->prime[m->i];a++)
	//	printf("%d\n",m->array[a].state);
	while(scanf("%s", command) > 0)
	{
		memset(k.text,0,sizeof(key));
		memset(v.text,0,sizeof(value));
		/*fgets(command,sizeof(command),stdin);
 		command[strlen(command)-1] = '\0';*/
 		//command[strlen(command)-1]='\0';

		//printf("Before define\n");
		//printf("%s\n",command);
		//print_table(m);
		if(strcmp(command,"Define") == 0)
		{

		//	printf("IN DEFINE: main \n");
			scanf("%s",k.text);
			//a=strlen(k);
 			//k[a-1]='\0';
 			scanf("%s",v.text);

			printf("Define Key:%s Value:%s\n", k.text, v.text);
			define(m,k,v);

		}
		else if (strcmp(command,"Delete") == 0)
		{
			//fgets(k,sizeof(k),stdin);
 			//k[strlen(k)-1] = '\0';
 			scanf("%s",k.text);
			printf("Delete key:%s\n", k.text);
			delete(m,k);

		}
		else if (strcmp(command,"Lookup") == 0)
		{

 			scanf("%s", k.text);
			printf("Lookup Key:%s\n",k.text);
			v1=lookup(m,k);
			if(v1)
				printf("Found Value:%s\n",v1);
			else
				 printf("No Value Found For Key:%s\n",k.text);

		}

	}
	//free(key);
	//free(value);
	return 0;
}







