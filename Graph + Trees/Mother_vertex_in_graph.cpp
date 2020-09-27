///A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.

#include<bits/stdc++.h>
using namespace std;
map<int,list<int>> adjList;
void dfs(int src,bool visited[])
{
  visited[src] = true;
  for(auto x:adjList[src])
  {
    if(!visited[x])
      dfs(x,visited);
  }
}
int findMother(int nodes)
{
  bool visited[nodes];
  memset(visited,false,sizeof(visited));
  int mother = 0;
  for(int i=0;i<nodes;i++)
  {
    if(!visited[i])
    {
      dfs(i,visited);
      mother = i;
    }
  }
  memset(visited,false,sizeof(visited));
  dfs(mother,visited);
  for(int i=0;i<nodes;i++)
  {
    if(visited[i]==false)
      {return -1;}
  }
  return mother;
}
void addEdge(int u,int v)
{
  ///Here we are checking the mother vertex for directed graph
  adjList[u].push_back(v);
}
int main()
{
    int nodes,edges;
    nodes=7,edges=8; 
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 3); 
    addEdge(4, 1); 
    addEdge(6, 4); 
    addEdge(5, 6); 
    addEdge(5, 2); 
    addEdge(6, 0); 
    int mother = findMother(nodes);
    if(mother==-1)
     cout<<"No mother vertex is present";
    else 
      cout << "A mother vertex is " << mother; 
  
    return 0; 
} 
