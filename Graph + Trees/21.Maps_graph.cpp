#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{

    //unordered_map<T,list<T> > adjList;
    map<T,list<T> > adjList;///In sorted order
public:
    Graph(){

    }

    void addEdge(T u,T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void printList(){
        for(auto row:adjList){
            T key = row.first;
            cout<<key<<"->";
            for(T element:row.second){
                cout<<element<<",";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph<string> g;
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Delhi","Siachen");
    g.addEdge("Delhi","Bangalore");
    g.addEdge("Delhi","Agra");
    g.addEdge("Amritsar","Siachen");

    g.printList();
    return 0;
}
