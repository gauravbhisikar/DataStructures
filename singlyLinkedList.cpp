#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

Node* nodeNext;
Node* Head;



void printList()
{   
    Node* head = Head;
	while(head->next!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
    cout<<endl;
}





//Create Head Node
createHead()
{
    Head = new Node();
    nodeNext = Head;
    
}


//Insert node at the end
void addNode(int data)
{
    if(Head==NULL)
    {
        createHead();
    }

    Node* newNode = new Node;
    nodeNext->next = newNode;
    nodeNext->data = data;
    nodeNext = newNode;
    nodeNext->next = NULL;
}


//Insert Node at the begining
InsertAtFront(int data)
{
    Node* firstNode = new Node();
    firstNode->data = data;
    firstNode->next = Head;
    Head = firstNode;

}

//Insert at specific position
InsertAt(int postion,int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    Node* point  = Head;
    for(int i=1;i<postion-1;i++)
    {
        point = point->next;
    }
    newNode->next = point->next;
    point->next = newNode;

}


//Delete Node 
deleteNode(int nodeNum)
{   
    if(nodeNum==1)
    {   
        Node* temp = Head;
        Head = temp->next;
    }

    else
    {
    Node* delNode;
    Node* prev;
    delNode = Head;
    for(int i=1;i<nodeNum;i++)
    {   
        prev = delNode;
        delNode = delNode->next;
        
    }
    prev->next = delNode->next;
    free(delNode);
    }

}


reverseListItter()
{
    Node*prev = NULL; 
    Node*Next;

    Node* current = Head;
    while(current->next!=NULL)
    {   
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
        
        
    }
        Head = prev;
}

 void printReverseList(Node* temp)
 {  
    
    if(temp->next==NULL)
    {
        return;
    }
    else{
        printReverseList(temp->next);
        cout<<temp->data<<" ";
    }
 }

 void revRec(Node* p)
 {  
    if(p->next==NULL)
    {   
        Head = p;
        return;

    }
    revRec(p->next);
    Node* q = p->next;
    p->next = NULL;
 }

int main()
{
    
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    addNode(7);

    cout<<"Print List"<<endl;
    printList();

    cout<<"\nInsert 0 at beginning "<<endl;
    InsertAtFront(0);
    printList();


    cout<<"\nDelete at position 2"<<endl;
    deleteNode(2);
    printList();

    cout<<"\nInsert 45 at position 4"<<endl;
    InsertAt(4,45);
    printList();

    cout<<"\nPrint List in reverse order"<<endl;
    printReverseList(Head);

    


}