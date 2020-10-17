#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

Node* head;
Node* tail;

void createHead(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	head = newNode;
	tail = newNode;
	newNode->next = head;

}

void addNode(int data)
{
	if(head==NULL)
	{
		createHead(data);
	}
	else{
		Node* newNode = new Node();
		newNode->data = data;
		tail->next = newNode;
		tail = newNode;
		newNode->next = head;
}

}

void showList()
	{
		Node* temp = head;
		while(temp->next!=head)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<tail->data<<endl;
	}


void InsertFront(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	tail->next = head;
}

void deleteNode(int n)
{
	Node* temp = head;
	Node* prev;
	for(int i=1;i<n;i++)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp==tail)
	{
		
		prev->next = head;
		free(temp);
		tail = prev;
	}
	else
	{
		prev->next = temp->next;
		free(temp);
	}
}

 void printReverseList(Node* temp)
 {  
    if(temp->next==head)
    {	
    	cout<<temp->data<<" ";
        return;
    }
    else{
        printReverseList(temp->next);
        cout<<temp->data<<" ";
    }
 }

int main()
{
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);
	addNode(6);
	InsertFront(0);
	showList();
	deleteNode(2);
	showList();
	printReverseList(head);

	
}