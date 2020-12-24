#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left = NULL;
	Node* right = NULL;
	int height;
};

int max(int a, int b)
{
	return (a>b)?a:b;
}

int height(Node* node)
{
	if(node==NULL)
		return 0;
	return node->height;
}


Node* newNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->height = 1;
	return(newNode); 
}

Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left  = T2; 

	y->height = max(y->left->height,y->right->height) + 1;
	x->height = max(x->left->height,x->right->height) + 1;

	return x;
}

Node* leftRotate(Node* y)
{
	Node* x = y->right;
	Node* T2 = x->left;

	y->left = x;
	x->right = T2;

	x->height = max(x->left->height,x->right->height) + 1;
	y->height = max(y->left->height,y->right->height) + 1;

	return y;
}


int balancefactor(Node* n)
{
	if(n==NULL)
		return 0;
	return n->left->height - n->right->height;
}


Node* insert(Node* node,int data)
{
	if(node == NULL)
		return newNode(data);

	if(data < node->data)
		node->left = insert(node->left,data);
	else if(data > node->data)
		node->right = insert(node->right,data);
	else
		return node;

	node->height = 1 + max(node->left->height,node->right->height);

	int balance = balancefactor(node);

	if (balance > 1 && data < node->left->data)  
        return rightRotate(node);  
 
    if (balance < -1 && data > node->right->data)  
        return leftRotate(node);  
  
    if (balance > 1 && data > node->left->data)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    if (balance < -1 && data < node->right->data)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  

}


void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}

int main()  
{  
    Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
      
    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  


    }  