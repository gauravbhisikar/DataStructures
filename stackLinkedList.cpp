#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next = NULL;
};

Node* top;
Node* head;
void push(int data)
{
	if(top==NULL)
	{
	Node* newNode = new Node();
	newNode->data = data;
	top = newNode;
	head = top;
	}
	else
	{
		Node* newNode = new Node();
		newNode->data = data;
		top->next = newNode;
		top = newNode;
	}

}

void pop()
{
	if(top==NULL)
	{
		cout<<"Stack is Empty"<<endl;
	}
	else{
		Node* temp = head;
		Node* prev;
		while(temp->next!=NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		top = prev;
		free(temp);


	}
}

void printList(Node* head)
{   
    stack<int> s;
	while(head!=NULL)
	{
		s.push(head->data);
		head = head->next;
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
    cout<<endl;
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	printList(head);
	pop();
	printList(head);
	push(5);
	printList(head);
}