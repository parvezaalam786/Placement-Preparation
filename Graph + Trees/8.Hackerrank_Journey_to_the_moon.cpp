#include <iostream>
#include<list>
using namespace std;


class Graph{

    long int V;
    list<long int> *l;

    public:
        Graph(long int v){
            V = v;
            l = new list<long int>[V];

        }

        void addEdge(long int u,long int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void dfsHelper(long int i,bool visited[],long int &country_size){
            visited[i] = true;
            country_size++;

            for(auto neighbour:l[i]){
                if(!visited[neighbour]){
                    dfsHelper(neighbour,visited,country_size);
                }
            }

        }

        long int dfsMoon(){
            bool *visited = new bool[V];
            for(long int i=0;i<V;i++){
                visited[i] = false;
            }

            long int n = V;
            long int total_ways = (n)*(n-1)/2;

            for(long int i=0;i<V;i++){
                if(visited[i]==false){
                    long int country_size = 0;
                    dfsHelper(i,visited,country_size);
                    //cout<<"Country Size "<<country_size<<endl;
                    total_ways -= (country_size)*(country_size-1)/2;
                }
            }
            return total_ways;
        }
};

int main() {
    long int n,p,x,y;
    cin>>n>>p;
    Graph g(n);
    for(long int i=0;i<p;i++){
        cin>>x>>y;
        g.addEdge(x,y);
    }
    cout<<g.dfsMoon();
}

