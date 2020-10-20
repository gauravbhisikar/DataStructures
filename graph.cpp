#include<bits/stdc++.h>
using namespace std;

template<typename dataType>
class Graph
{	
	map<dataType,list<dataType> > adjList;
	
	public:
		
		void addEdge(int x,int y)
		{
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}

		
		void bfs(dataType srcNode)
		{
			map<dataType,int> visited;
			queue<dataType> q;
			q.push(srcNode);
			visited[srcNode] = true;

			while(!q.empty())
			{
				dataType node = q.front();
				cout<<node<<" ";
				q.pop();

				for(int nbr:adjList[node])
				{
					if(!visited[nbr])
					{
						q.push(nbr);
						visited[nbr] = true;
					}
				}
			}
			cout<<endl;

		}

		void dfsHelper(dataType src, map<dataType,bool> &visited)
		{
			cout<< src <<" ";
			visited[src] = true;
			for(dataType nbr: adjList[src])
			{
				if(!visited[nbr])
				{
					dfsHelper(nbr,visited);
				}
			}
		}

		void dfs(dataType src)
		{
			map<dataType,bool> visited;
			for (auto p:adjList)
			{
				dataType node = p.first;
				visited[node] = false;
			}
			dfsHelper(src,visited);
			cout<<endl;
		}

		void printAdjList()
		{
			
		for(auto a:adjList)
		{
			cout<<a.first<<"->";
			for(auto it = a.second.begin(); it != a.second.end(); ++it)
			{
				cout<<*it<<',';
				
			}
			cout<<endl;

		}
		}


};


int main()
{
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,3);
	g.printAdjList();
	g.bfs(3);
	g.dfs(3);

}