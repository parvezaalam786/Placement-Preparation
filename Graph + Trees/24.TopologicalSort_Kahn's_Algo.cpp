#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *adjList;
public:
    Graph(int V){
        this->V = V;
        adjList = new list<int>[V];
    }
    void addEdge(int u,int v){
        adjList[u].push_back(v);  
    }
    void topologicalSort(){
        vector<int> in_degree(V,0);
        for(int i=0;i<V;i++){
            for(auto it1=adjList[i].begin();it1!=adjList[i].end();it1++){
                in_degree[*it1]++;            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(in_degree[i]==0){
                q.push(i);
            }
        }
        int cnt = 0;
        vector<int> topo_order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo_order.push_back(node);
            for(auto it1 = adjList[node].begin();it1!=adjList[node].end();it1++){
                in_degree[*it1]--;
                if(in_degree[*it1]==0)
                    q.push(*it1);   
            }
            cnt++; 
        }
        if(cnt!=V){
            cout<<"The graph is not DAG"<<endl;
            return ;
        }
        for(int i=0;i<topo_order.size();i++){
            cout<<topo_order[i]<<"-->";
        }
        cout<<endl;
    }
};
int main()
{
   
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

    cout<<"Topological Order: ";
    g.topologicalSort();
    return 0;

}