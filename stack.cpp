#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
	int top = -1,count=0;
	int s;
	vector<int> stack;
	Stack(int size)
	{	
		s = size;
		vector<int> stack(size);
	}
	void push(int data)
	{	
		if(count!=s)
		{
		stack.push_back(data);
		top += 1;
		count+=1;
		}
		else{
			cout<<"Stack Overflow"<<endl;
		}
	}
	void pop()
	{
		if(top==-1)
		{
			cout<<"Stack is empty"<<endl;
		}
		else
		{
			stack.pop_back();
			top -= 1;
		}
	}

	void showStack()
	{
		for(int i = top;i>-1;i--)
		{
			cout<<stack[i]<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	Stack stack(4);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.showStack();
	stack.pop();
	stack.showStack();
}