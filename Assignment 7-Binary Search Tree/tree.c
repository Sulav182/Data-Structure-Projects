//Sulav Poudyal
//Data Structures
//Assignment 7 : 3/25/2016
#include"tree.h"

node* recRemove(node* root,node* node);

tree* createTree()
{
	tree* t = (tree*) malloc(sizeof(tree));
	t->root=NULL;
	return t;
}





void insertNode(tree *t, int data)
{
	node* n = (node*) malloc(sizeof(node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	if(t->root==NULL)
		t->root=n;
	else
		t->root = recInsert(t->root,n);
}


node* recInsert(node* m, node* n)
{

	if(m==NULL)
	return n;

	//if(m->data == n->data)
	//{
	//	n->left = m;
	//	n->right = m->right;
	//	m->right = NULL;
	//	return n;
	//}
	//else
	if(n->data <= m->data)
	{
		m->left = recInsert(m->left , n);
	}
	else
	{
		m->right = recInsert(m->right , n);

	}

}

/*void treeWalk(tree* t)
{
	recTraversal(t->root);
}*/

void preOrder(node* n)
{
	if(n==NULL)
		return;

	printf("%d ", n->data);
	preOrder(n->left);
	preOrder(n->right);

}

void inOrder(node* n)
{
	if(n==NULL)
		return;

	inOrder(n->left);
	printf("%d ", n->data);
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
*/
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
node* findMax(node* n)
{
	while(n->right != NULL)
		n = n->right;
	return n;
}

void removeNode(node* n, int d)
{
	node *temp = Delete(n,d);
	printf("Removed node %d", temp->data);
}

int search(node* n, int d)
{

	if(n->data ==d)
		return 1;
	else if(d < n->data)
		return search(n->left,d);
	else if(d>n->data)
		return search(n->right,d);
	else
	return 0;
}

node* Delete(node *n, int d)
{

	if(n == NULL)
		return n;
	else if(d < n->data)
		n->left = Delete(n->left,d);
	else if (d > n->data)
		n->right = Delete(n->right,d);
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
			node *temp = findMax(n->left);
			n->data = temp->data;
			n->left = Delete(n->left,temp->data);
		}
	}

	return n;
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







