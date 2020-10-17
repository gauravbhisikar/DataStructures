#include<bits/stdc++.h>
using namespace std;


class Queue
{
public:
	vector<int> queue;
	int front = -1;
	int rear = -1;
	int track = 0;
	Queue(int size)
	{
		
		vector<int> queue(size);
		
	}

	void enqueue(int data)
	{
		if(queue.empty())
		{
			queue.push_back(data);
			front += 1;
			rear  += 1;
			
			
		}
		else{
			queue.push_back(data);
			rear+=1;
			
			
		}
	}

	void dequeue()
	{
		if(front==rear)
		{	
			front= -1;
			rear = -1;
			cout<<"Queue is empty\n";
		}
		else{
			front+=1;
		    }
	}


	void showStack()
	{	
		if(front!=-1 and rear!=-1)
		{
		for(int i =front;i<=rear;i++)
		{
			cout<<queue[i]<<" ";
		}
		}
	}
	
	
};

int main()
{
	Queue q(4);
	q.enqueue(10);
	q.enqueue(22);
	q.enqueue(23);
	q.dequeue();
	q.dequeue();
	q.showStack();

}