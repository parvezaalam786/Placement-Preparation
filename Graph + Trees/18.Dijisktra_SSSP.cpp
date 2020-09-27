#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Graph{
    unordered_map<int,list<pair<int,int>> > m;
public:
    void addEdge(int u,int v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }
    void printAdj(){
        for(auto j:m){
            cout<<j.first<<"->";
            for(auto l:j.second){
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }
    }
    void dijsktraSSSP(int src){
        unordered_map<int,int> dist;
        for(auto j:m){
            dist[j.first] = INT_MAX; 
            }  //pair is disstance then vertex name
            set<pair<int,int> > s;
            dist[src] = 0;
            s.insert(make_pair(0,src));
            while(!s.empty()){
                auto p = *(s.begin());//front is pair
                int node = p.second;
                int nodeDist = p.first;
                s.erase(s.begin());
                //Iterate over neighbours of current node
                for(auto childPair:m[node]){
                    if(nodeDist+childPair.second < dist[childPair.first]){
                        //in the set updation of a particular element is not possible
                        //we have to remove old pair , and insert the new pair to ssimulate updation
                        int dest = childPair.first;
                        auto f = s.find(make_pair(dist[dest],dest));
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        //Insert new pair
                        dist[dest] = nodeDist + childPair.second;
                        s.insert(make_pair(dist[dest],dest));     
                    }
                }   
        }
        for(auto d:dist){
            cout<<d.first<<"-"<<d.second<<endl; 
        }
    }    
};

int main()
{
    Graph g;
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.addEdge(7,8,7);
    g.addEdge(7,6,1);
    g.addEdge(2,8,2);
    g.addEdge(8,6,6);
    g.addEdge(2,3,7);
    g.addEdge(6,5,2);
    g.addEdge(3,5,14);
    g.addEdge(3,4,9);
    g.addEdge(5,4,10);
    g.addEdge(2,5,4);
    g.printAdj();
    g.dijsktraSSSP(0);

}