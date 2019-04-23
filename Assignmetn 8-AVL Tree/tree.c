//Sulav Poudyal
//Data Structures
//Assignment 8 : 4/4/2016
#include"tree.h"

node* recAVLremove(node*root, int e, int* a);

void recHeight(node* n);
tree* createTree()
{
	tree* t = (tree*) malloc(sizeof(tree));
	t->root=NULL;
	return t;
}





void insert(tree *t, int data)
{
	node* n = (node*) malloc(sizeof(node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	n->height=1;
	if(t->root==NULL)
		t->root=n;
	else
		t->root = recAVLInsert(t->root, n->data);
}


/*node* recAVLInsert(node* n, int e)
{


	//if(m->data == n->data)
	//{
	//	n->left = m;
	//	n->right = m->right;
	//	m->right = NULL;
	//	return n;
	//}
	//else
	if(n->data < e)
	{
		n->right = recAVLInsert(n->right ,e);
	}
	else
	{
		n->left = recAVLInsert(n->left ,e);

	}
	if((height(n->left)-height(n->right))>1)
	{
		if(height(n->left->right)>height(n->left->left))
		{
			n->left=rotateLeft(n->left)
			return rotateRight(n);
		}
	}
	else if((height(n->right)-height(n->left))>1)
	{
		if(height(n->right->left)>height(n->right->right))
		{
			n->right= rotateRight(n->right)
			return rotateLeft(n);
		}
	}
	else
	{
		recalcHeight(n);
		return(n);
	}

}

*/


/*void treeWalk(tree* t)
{
	recTraversal(t->root);
}*/

void preOrder(node* n)
{
	if(n==NULL)
		return;
		//printf("Inside preorder 1\n");

	printf("%d ", n->data);
	//printf("Inside pre 2\n");
	preOrder(n->left);
	preOrder(n->right);

}

void inOrder(node* n)
{
	//printf("Inside inorder 1\n");
	if(n==NULL)
		return;
	//printf("Inside inorder 2\n");
	inOrder(n->left);
	//printf("Inside inorder 3\n");
	printf("%d ", n->data);
	//printf("Inside inorder 4\n");
	inOrder(n->right);

}

void postOrder(node* n)
{
	if(n==NULL)
		return;


	postOrder(n->left);
	postOrder(n->right);
	printf("%d ", n->data);

}

/*void removeNode(tree* t, node* n)
{
	if(t==NULL)
		return;
	//if(t->root=NULL)
	//	return;
	if(t->root==n)
	{
		if(t->root->left==NULL)
		{
			t->root=t->root->right;
			n->right=NULL;
		}
		else if(t->root->right==NULL)
		{
			t->root=t->root->left;
			n->left=NULL;
		}
		else
		{
			t->root=n->left;
			t->root=recInsert(t->root,n->right);
			n->right=NULL;
			n->left=NULL;
		}
	}
	else if(t->root->data < n->data)
	{
		t->root->right=recRemove(t->root->right,n);
	}
	else
	{
		t->root->left=recRemove(t->root->left,n);
	}
}

node* recRemove(node* root,node* n)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root==n)
	{
		node* newRoot = root->left;
		newRoot = recInsert(newRoot,root->right);
		n->left= NULL;
		n->right=NULL;
		return newRoot;
	}
	else if(root->data < n->data)
	{
		root->right = recRemove(root->right,n);
	}
	else
		root->left = recRemove(root->left,n);

	return root;

}

int recCalculate(node* n)
{
	int A=0,B=0;

	if(n==NULL)
	{
		return 0;
	}
	if(n->left == NULL && n->right == NULL)
	{

		return n->data;
	}
	A = recCalculate(n->left);
	B = recCalculate(n->right);
	return ((n->data)*(A-B));

}
*/
node* findMin(node* n)
{
	while(n->left != NULL)
		n = n->left;
	return n;
}
/*
void removeNode(node* n, int d)
{
	node *temp = Delete(n,d);
	printf("Removed node %d", temp->data);
}


node* Delete(node *n, int d, int* a)
{

		if(n == NULL)
		{
			*a=0;
			return n;
		}
		else if(d < n->data)
			n->left = Delete(n->left,d,a);
		else if (d > n->data)
			n->right = Delete(n->right,d,a);

		else {
			// Case 1:  No child
			if(n->left == NULL && n->right == NULL) {
				free(n);
				n = NULL;
			}
			//Case 2: One child
			else if(n->left == NULL) {
				node* temp = n;
				n = n->right;
				free(temp);
			}
			else if(n->right == NULL) {
				node* temp = n;
				n = n->left;
				free(temp);
			}
			// case 3: 2 children
			else {
				node *temp = findMin(n->right);
				n->data = temp->data;
				n->right = Delete(n->right,temp->data,a);
			}
		}
		*a=1;
		recHeight(n);
		return rebalance(n);
}




void deleteTree(node** n)
{
	if((*n)==NULL)
	return;
	deleteTree(&(*n)->left);
	deleteTree(&(*n)->right);

	if(!(*n)->left && !(*n)->right)
	{
		free(*n);
		*n=NULL;
	}

}
*/
node *rotateRight(node*n)
{
	if(n==NULL)
	{
		printf("RotateRight NULL NULL NULL\n");
		return NULL;
	}

	if(n->left == NULL)
	{
		printf("RotateRight NULL %d %d\n", n->data,n->right->data);
		return n;
	}
	else if(n->right==NULL)
		printf("RotateRight %d %d NULL\n", n->left->data,n->data);
	else
		printf("RotateRight %d %d %d\n", n->left->data,n->data,n->right->data);

	node* nl=n->left;
	n->left=nl->right;
	nl->right = n;
	//rotateRight(n);
	//rotateRight(nl);
	recHeight(n);
	recHeight(nl);
	return nl;
}
node *rotateLeft(node*n)
{
	if(n==NULL)
	{
		printf("RotateLeft NULL NULL NULL\n");
		return NULL;
	}

	if(n->left == NULL)
	{
		printf("RotateLeft NULL %d %d\n", n->data,n->right->data);

	}
	else if(n->right==NULL)
	{
		printf("RotateLeft %d %d NULL\n", n->left->data,n->data);
		return n;
	}
	else
		printf("RotateLeft %d %d %d\n", n->left->data,n->data,n->right->data);

	node* nr=n->right;

	n->right=nr->left;
	nr->left = n;
	//rotateLeft(n);
	//rotateLeft(nr);
	recHeight(n);
	recHeight(nr);
	return nr;
}
int height(node *n)
{
	if(n==NULL)
		return 0;
	return n->height;
}
int max(int a,int b)
{
	if (a>b)
		return a;
	else
		return b;
}

void recHeight(node* n)
{
	if(n==NULL)
		return;
	n->height = max(height(n->left),height(n->right))+1;
}
node *rebalance(node*n)
{
	//printf("Inside rebalance 1\n");
	if(n==NULL)
		return NULL;
	int diff= height(n->left)-height(n->right);
	if(diff>= -1 && diff <= 1)
		return n;
	if(diff<-1)//left height lesser
	{
		if(height(n->right->left)>height(n->right->right))
		{
			n->right= rotateRight(n->right);
		}
			//printf("Inside rebalance 2\n");
			return rotateLeft(n);

	}
	if(diff>1)
	{
		if(height(n->left->right)>height(n->left->left))
		{
			n->left=rotateLeft(n->left);
			//printf("Inside rebalance 3\n");
		}
			return rotateRight(n);

	}
}
node* recAVLInsert(node* n, int e)
{

	if(n==NULL)
	{

	node* n = (node*) malloc(sizeof(node));
		n->data = e;
		n->left = NULL;
		n->right = NULL;
		n->height=1;

		return n;
	}

	if(n->data < e)
	{
		n->right = recAVLInsert(n->right ,e);
	}
	else
	{
		n->left = recAVLInsert(n->left ,e);

	}
	recHeight(n);
	return rebalance(n);
}


node *removeLargestNode(node *n,node** least)
{
	 if(n==NULL)
	    {
	        (*least)=NULL;
	        return NULL;
	    }
	    else
	    {
	        if(n->left==NULL)
	        {
	            (*least)=n;
	            return (*least)->right;
	        }
	        else
	        {
	            n->left=removeLargestNode(n->left, least);
	            rebalance(n);
	            return n;
	        }
    }
}
/*node* getLeastNode(node* n, node** least)
{
    if(n==NULL)
    {
        (*least)=NULL;
        return n;
    }
    else
    {
        if(n->left==NULL)
        {
            (*least)=n;
            return (*least)->right;
        }
        else
        {
            n->left=getLeastNode(n->left, least);
            rebalance(n);
            return n;
        }
    }
}
*/
node* recAVLremove(node* root, int e,int *a)
{
	if(root==NULL)
	{
		*a=0;
		return root;
	}
	if(e<root->data)
	{
		root->left= recAVLremove(root->left,e,a);

		return rebalance(root);
	}
	else if(e>root->data)
	{
		root->right=recAVLremove(root->right,e,a);
		return rebalance(root);
	}
	else
	{
		node* newroot;
		if(root->left==NULL)
		{
			newroot=root->right;
			root->right=NULL;
			*a=1;
			free(root);
			return newroot;
		}
		else if(root->right==NULL)
		{
			newroot=root->left;
			root->left=NULL;
			*a=1;
			free(root);
			return newroot;
		}
		else
		{

			node* rightsubtree = removeLargestNode(root->right,&newroot);
			//printf("Inside removeNode 2\n");
			newroot->left=root->left;
			//printf("Inside removeNode 3\n");
			newroot->right=rightsubtree;
			//printf("Inside removeNode 4\n");
			root->left=root->right=NULL;
			//printf("Inside removeNode 5\n");
			*a=1;
			free(root);
			//printf("Inside removeNode 6\n");
			recHeight(newroot);
			return rebalance(newroot);
		}
	}

}



/*
node* recAVLremove(node* root, int e, int* a)
{
     if(root==NULL)
     {
        *a=0;
        return root;
    }
    if(e<root->data)
    {

        root->left=recAVLremove(root->left, e, a);
        return rebalance(root);
    }
    else if(e > root->data)
    {

        root->right=recAVLremove(root->right, e, a);
        return rebalance(root);
    }
    else
    {

        node* newroot;
        if(root->right==NULL)
        {

            *a=1;
            newroot=root->left;
            root->left=NULL;
            free(root);
            return newroot;
        }
        else if(root->left==NULL)
        {
            *a=1;
             newroot=root->right;
            root->right=NULL;
            free(root);
            return newroot;
        }
        else
        {
            *a=1;
            node* rightsubtree;
            rightsubtree = getLeastNode(root->right, &newroot);
           // printf("Finished get least\n");
            newroot->left=root->left;
            newroot->right=rightsubtree;
            root->left=root->right=NULL;
            //printf("Assigned from least\n");
            free(root);
            //printf("Finished removing\n");
            recHeight(newroot);
            //printf("\n WORK\n");
            return rebalance(newroot);
        }
    }
}
*/