#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int val;
	node *left;
	node *right;
};

node *creatnode(int x)
{
	node *tmp = new node();
	tmp->val = x;
	tmp->left = tmp->right = NULL;
	return tmp;
}

node *buildtree()
{
	node *root = creatnode(1);
	node *n1 = creatnode(2);
	node *n2 = creatnode(3);
	node *n3 = creatnode(4);
	node *n4 = creatnode(5);
	node *n5 = creatnode(6);
	node *n6 = creatnode(7);
	node *n7 = creatnode(8);
	node *n8 = creatnode(9);
	//node *n9 = creatnode(10);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n3->left = n5; 
	n3->right = n6;
	n4->left = n7;
	n2->right = n8;
	return root;
}

void pretravel(node *root)
{
	if (root != NULL)
	{
		cout << root->val << "  ";
		pretravel(root->left);
		pretravel(root->right);
	}
}

void midtravel(node *root)
{
	if (root != NULL)
	{
		midtravel(root->left);
		cout << root->val << "  ";
		midtravel(root->right);
	}
}

void posttravel(node *root)
{
	if (root != NULL)
	{
		posttravel(root->left);
		posttravel(root->right);
		cout << root->val << "  ";
	}
}

void leveltravel(node *root)
{
	queue<node*> Q;

	if (root != NULL)
		Q.push(root);
	node *tmp;
	while (!Q.empty())
	{
		tmp = Q.front();
		Q.pop();
		cout << tmp->val << "  ";
		if (tmp->left != NULL)
			Q.push(tmp->left);
		if (tmp->right != NULL)
			Q.push(tmp->right);
	}
}

int main()
{
	node *root = buildtree();
	pretravel(root);
	cout << endl;

	midtravel(root);
	cout << endl;

	posttravel(root);
	cout << endl;

	leveltravel(root);
	cout << endl;

	system("pause");
	return 0;
}
