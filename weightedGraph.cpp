#include<bits/stdc++.h>
using namespace std;

template<typename T>

class WeightedGraph
{
	unordered_map<T,list<pair<T,int> > >adjList;
public:
	
	void addEdge(T x,T y ,int wt ,bool bidir)
	{
		adjList[x].push_back(make_pair(y,wt));
		if(bidir)
		{
			adjList[y].push_back(make_pair(x,wt));
		}
	}

	void printList()
	{
		for(auto city:adjList)
		{	
			cout<<city.first<<"->";
			for(auto nbr:city.second)
			{
				cout<<"("<<nbr.first<<","<<nbr.second<<")"<<" ";
			}
			cout<<endl;
		}
	}

	void bfs(T src)
	{
		queue<T> q;
		map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto nbr:adjList[node])
			{
				if(!visited[nbr.first])
				{
					q.push(nbr.first);
					visited[nbr.first] = true;
				}
			}
		}
		cout<<endl;
	}

	void dfsHelper(T src,map<T,bool> &visited)
	{
		cout<<src<<" ";
		visited[src] = true;

		for(auto nbr:adjList[src]){
			if (!visited[nbr.first])
			{
				dfsHelper(nbr.first,visited);
			}
		}
	}

	void dfs(T src)
	{
		map<T,bool> visited;
		for(auto c: adjList)
		{
			T node = c.first;
			visited[node] = false;
		}
		dfsHelper(src,visited);
		cout<<endl;

	}

	void dijkstras(T src)
	{
		unordered_map<T,int> dist;
		set<pair<int,T>> s;
		for(auto i:adjList)
			dist[i.first] = INT_MAX;

		dist[src] = 0;
		s.insert(make_pair(0,src));

		while(!s.empty())
		{
			auto p = *(s.begin());
			T node = p.second;

			int nodeDist = p.first;
			s.erase(s.begin());

			for(auto childPair:adjList[node])
			{
				if(nodeDist + childPair.second < dist[childPair.first])
				{
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f!=s.end())
					{
						s.erase(f);
					}
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}

		}

		for(auto d:dist)
		{
			cout<<d.first<<" is located at distance of "<<d.second<<endl;
		}

	}
};


int main()
{
	WeightedGraph<string> city;
	city.addEdge("Mumbai","Delhi",9,true);
	city.addEdge("Nagpur","Delhi",4,true);
	city.addEdge("Nagpur","Mumbai",2,true);
	city.addEdge("Pune","Nagpur",5,true);
	city.addEdge("Banglore","Delhi",7,true);
	city.addEdge("Banglore","Nagpur",6,true);
	city.printList();
	cout<<"\n_______________BFS_____________\n";
	city.bfs("Nagpur");
	cout<<"\n_______________DFS_____________\n";
	city.dfs("Nagpur");
	cout<<"\n___________Dijkstra's__________\n";
	city.dijkstras("Nagpur");
}