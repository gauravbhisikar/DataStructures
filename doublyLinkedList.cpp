#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;
};

Node* Head;
Node* lastNode;

void createHead(int data)
{
	Node* head = new Node();
	head->data = data;
	head->next = NULL;
	head->prev = Head;
	Head = head;
	lastNode = head;
}

void addNode(int data)
{
	
	 if(Head==NULL)
    {
        createHead(data);
    }
    else
    {
    	Node* newNode = new Node();
    	lastNode->next = newNode;
    	newNode->prev = lastNode; 
    	newNode->data = data;
    	lastNode = newNode;
    	lastNode->next = NULL;
	}
}

void printList()
{
	Node* temp;
	temp = Head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void InsertFront(int data)
{
	Node* newNode = new Node();
	newNode ->data = data;
	newNode->next = Head;
	Head = newNode;
}

void deleteNode(int n)
{	
	  if(n==1)
    {   
        Node* temp = Head;
        Head = temp->next;
        free(temp);

    }

    else{
	Node* delNode = Head;
	Node* prev;
	for(int i=1;i<n;i++)
	{
		delNode = delNode->next;
		prev = delNode->prev; 
	}
	if(delNode->next!=NULL)
	{
	prev->next = delNode->next;
	delNode->next->prev = prev;
	free(delNode);
	}
	else{
		prev->next = NULL;
		free(delNode);
	}

	}
	
}

 void printReverseList(Node* temp)
 {  
    if(temp==NULL)
    {
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
	printList();
	
	// InsertFront(45);
	// InsertFront(0);
	// printList();
	deleteNode(4);
	printList();
	printReverseList(Head);

}