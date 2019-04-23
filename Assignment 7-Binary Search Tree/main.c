//Sulav Poudyal
//Data Structures
//Assignment 7 : 3/25/2016

#include"tree.h"

int main(int argc,char **argv)
{
	char command[100];
	int data1, data2;
	tree* t =(tree*) createTree();

	while(scanf("%s", command) > 0)
	{
		if(strcmp(command, "insert") == 0)
		{
			scanf("%d", &data1);
			insertNode(t,data1);

		}
		else if(strcmp(command, "preorder") == 0)
		{
			if(t->root==NULL)
				printf("Tree is Empty\n");
			else
			{
				preOrder(t->root);
				printf("\n");
			}
		}

		else if(strcmp(command, "inorder") == 0)
		{
			if(t->root==NULL)
				printf("Tree is Empty\n");
			else
			{
				inOrder(t->root);
				printf("\n");
			}
		}
		else if(strcmp(command, "postorder") == 0)
		{
			if(t->root==NULL)
				printf("Tree is Empty\n");
			else
			{
				postOrder(t->root);
				printf("\n");
			}
		}
		else if(strcmp(command, "calculate") == 0)
		{
			if(t->root==NULL)
				printf("Tree is Empty\n");
			else
				printf("%d\n",recCalculate(t->root));
		}
		else if(strcmp(command, "remove") == 0)
		{

			if(t->root==NULL)
				printf("Tree is Empty\n");
			else
			{
				scanf("%d",&data2);
				int a=data2;
				//printf("In remove main");
				t->root = Delete(t->root,data2);


			}
	    }
		else if(strcmp(command, "clear") == 0)
		{
			deleteTree(&t->root);

		}

	}


return 0;
}
