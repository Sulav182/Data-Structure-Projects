//Sulav Poudyal
//Data Structures
//Assignment 8 : 4/4/2016

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

			t->root=recAVLInsert(t->root,data1);

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

		else if(strcmp(command, "remove") == 0)
		{

			if(t->root==NULL)
				printf("Tree is Empty\n");
			else
			{
				scanf("%d",&data2);
				int a;

				//printf("In remove main");
				do
				{
					t->root = recAVLremove(t->root,data2,&a);
				}while(a==1);

			}
	    }
	}


	return 0;
}
