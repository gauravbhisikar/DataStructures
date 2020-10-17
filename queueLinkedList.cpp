#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear  = NULL;

void enqueue(int data)
{
	if(front==NULL)
	{
		Node* newNode = new Node();
		newNode->data = data;
		front = newNode;
		rear = newNode;
	}
	else{
		Node* newNode = new Node();
		newNode->data = data;
		rear->next = newNode;
		rear = newNode;
	}
}

void dequeue()
{
	if(rear==front)
	{
		front = NULL;
	}
	else if(rear==NULL)
	{
		cout<<"Queue is empty"<<endl;
	}
	else{
		Node* temp = front->next;
		free(front);
		front = temp;

	}
}

void showQueue()
{
	Node* temp = front;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	showQueue();
	dequeue();
	dequeue();
	dequeue();
	showQueue();
}