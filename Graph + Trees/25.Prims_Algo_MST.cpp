#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
    int v;
    list<pair<int,int> > *adj;
    Graph(int v){
        this->v = v;
        adj = new list<pair<int,int> >[v];
    }
    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int findMinVertex(int *weight,bool *visited,int v){
        int minVertex = -1;
        for(int i=0;i<v;i++){
            if(!visited[i] and (minVertex == -1 or weight[i]<weight[minVertex])){
                minVertex = i;
            }
        }
        return minVertex;
    }
    void Prims(){
        bool *visited = new bool[v];
        int *parent = new int[v];
        int *weight = new int[v];
        for(int i=0;i<v;i++){
            visited[i] = false;
            weight[i] = INT_MAX;
        }
        parent[0] = -1;
        weight[0] = 0;
        for(int i=0;i<v;i++){
            int minVertex = findMinVertex(weight,visited,v);
            visited[minVertex] = true;
            for(auto neighbour:adj[minVertex]){
                if(!visited[neighbour.first]){
                    if(weight[neighbour.first]>neighbour.second){//If the weight for a vertex in our mapping is greater than the weight at a particular edge or not
                        parent[neighbour.first] = minVertex;
                        weight[neighbour.first] = neighbour.second;
                    }
                }
            }
        }
        for(int i=1;i<v;i++){
            cout<<i<<"--"<<parent[i]<<" with eight "<<weight[i]<<endl;
        }
    }
};
int main()
{
    Graph g(7);
//Edges = 8
    g.addEdge(0,3,4);
    g.addEdge(0,1,6);
    g.addEdge(1,2,5);
    g.addEdge(3,2,7);
    g.addEdge(3,4,2);
    g.addEdge(4,5,4);
    g.addEdge(5,6,1);
    g.addEdge(4,6,3);
    g.Prims();

}