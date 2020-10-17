#include<bits/stdc++.h>
using namespace std;


class Graph
{
	unordered_map<string, list< pair<string,int> > > l;
public:

		void addEdge(string x, string y, bool bidir, int wt)
		{
			l[x].push_back(make_pair(y,wt));
			if(bidir)
			{
				l[y].push_back(make_pair(x,wt));
			}			
		}
};

int main()
{
	Graph g;
	g.addEdge("A","B",true,10);
	g.addEdge("A","C",true,5);
	g.addEdge("B","C",true,4);
	g.addEdge("B","D",true,7);
	g.addEdge("C","E",true,8);
	g.addEdge("D","C",true,2);
	g.addEdge("D","F",true,6);
	g.addEdge("E","F",true,2);

}
