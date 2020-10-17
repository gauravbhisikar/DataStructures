#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node* left = NULL;
	Node* right = NULL;
};

Node* root = NULL;




class Utility
{
public:
	void preorderItterative()
	{
		if(root==NULL)
			return;

		stack<Node*> nodeStack;
		nodeStack.push(root);

		while(nodeStack.empty() == false)
		{
			Node* node = nodeStack.top();
			cout<<node->data<<" ";
			nodeStack.pop();

			if(node->right)
				nodeStack.push(node->right);
			if(node->left)
				nodeStack.push(node->left);
		}
		cout<<endl;

	}

	void inorderItterative()
	{
		if(root==NULL)
		{
			return;
		}

		stack<Node*> nodeStack;
		Node* current = root;

		while(current!=NULL || nodeStack.empty() == false)
		{
			while(current!=NULL)
			{
				nodeStack.push(current);
				current = current->left;
			}
		

		current = nodeStack.top();
		nodeStack.pop();

		cout<<current->data<<" ";

		current = current->right;
		
		}
		cout<<endl;
	}

	void postorderIttrative()
	{
		if(root==NULL)
		{
			return;
		}

		stack<Node*> s1,s2;
		s1.push(root);
		Node* node;
		

		while(!s1.empty())
		{
			node = s1.top();
			s1.pop();
			s2.push(node);

			if(node->left)
				s1.push(node->left);
			if(node->right)
				s1.push(node->right);
		}

		while(!s2.empty())
		{
			node = s2.top();
			s2.pop();
			cout<<node->data<<" ";
		}
		cout<<endl;
	}

	void printLevelOrder()
	{
		if(root==NULL)
			return;
		queue<Node*> nodeQueue;
		nodeQueue.push(root);
		while(!nodeQueue.empty())
		{
			Node* current = nodeQueue.front();
			cout<<current->data<<" ";
			if(current->left!=NULL)
				nodeQueue.push(current->left);
			if(current->right!=NULL)
				nodeQueue.push(current->right);
			nodeQueue.pop();
		}
		cout<<endl;
	}

	int maxDepthUtil(Node* node)
	{
		if(node==NULL)
			return 0;
		
		int ldepth = maxDepthUtil(node->left);
		int rdepth = maxDepthUtil(node->right);

		if(ldepth>rdepth)
			return(ldepth+1);
		else
			return (rdepth+1);
	}

	int maxDepth()
	{
		return maxDepthUtil(root);
	}

	bool isSymmetricUtil(Node* root1,Node* root2)
	{
		if(root1==NULL && root2==NULL)
		{
			return true;
		}

		if(root1&&root2 && root1->data == root2->data)
			return isSymmetricUtil(root1->left,root2->right) && isSymmetricUtil(root1->right,root2->left);

		return false;
	}

	bool isSymmetric()
	{
		return isSymmetricUtil(root,root);
	}

	bool hasPathSumUtil(Node* node,int sum)
	{
		if(node==NULL){
			return false;
		}
		else if(node->left==NULL && node->right==NULL && sum-node->data==0)
			{
				return true;
			}
		else{
			return hasPathSumUtil(node->left,sum-node->data) || hasPathSumUtil(node->right,sum-node->data);
		}

	}

	bool hasPathSum(int sum)
	{
		return hasPathSumUtil(root,sum);
	}


};





class BST : public Utility
{
	public:

		//Insert New Node
		void InsertNode(int data)
		{
			if(root==NULL)
			{
				Node * newNode = new Node;
				newNode->data = data;
				root = newNode;
			}
			else
			{	
				Node* newNode = new Node();
				newNode->data = data;
				Node* temp1 = root;
				Node* temp2 = NULL;
					while(temp1!=NULL)
					{
						temp2 = temp1;
						if(data < temp1->data)
							temp1 = temp1->left;
						else
							temp1 = temp1->right;

					}

					if(temp2==NULL)
					{
						temp2 = newNode;
					}
					else if(data < temp2->data)
					{
						temp2->left = newNode;
					}

					else
						temp2->right = newNode;
				
			}
		}

		//Recursive method of preorder traversal
		void printPreorderUtil(Node* node)
		{
			if(node == NULL)
				return;

			cout<<node->data<<" ";
			printPreorderUtil(node->left);
			printPreorderUtil(node->right);
		}

		void printPreorder()
		{
			printPreorderUtil(root);
			cout<<endl;
		}


		//Recursive method of Ineorder traversal
		void printInorderUtil(Node* node)
		{
			if(node == NULL)
				return;

			printInorderUtil(node->left);
			cout<<node->data<<" ";
			printInorderUtil(node->right);
		}

		void printInorder()
		{
			printInorderUtil(root);
			cout<<endl;
		}

		//Recursive method of postorder traversal
		void printPostorderUtil(Node* node)
		{
			if(node == NULL)
				return;

			printPostorderUtil(node->left);
			printPostorderUtil(node->right);
			cout<<node->data<<" ";
		}

		void printPostorder()
		{	
			printPostorderUtil(root);
			cout<<endl;
		}


		bool isBST(Node* n)
		{
			return isBST(n,INT_MIN,INT_MAX);
		}
		bool isBST(Node* node,int min,int max)
		{

			if(node==NULL)
				return true;

			if(node->data < min || node->data > max)
				return false;

			isBST(node->left,min,node->data) && isBST(node->right,node->data+1,max);

		}


};





int main()
{
	BST bst;
	bst.InsertNode(4);
	bst.InsertNode(5);
	bst.InsertNode(2);
	bst.InsertNode(9);
	bst.InsertNode(1);
	bst.InsertNode(3);
	
	
	// bst.printInorder();
	// bst.inorderItterative();

	// bst.printPreorder();
	// bst.preorderItterative();

	// bst.printPostorder();
	// bst.postorderIttrative();

	// if(bst.isBST(root))
	// {
	// 	cout<<"BST"<<endl;
	// }
	// else{
	// 	cout<<"NOT BST"<<endl;
	// }
	
	// bst.printLevelOrder();
	// cout<<bst.maxDepth()<<endl;

	cout<<bst.isSymmetric()<<endl;
	cout<<bst.hasPathSum(9)<<endl;
	
}