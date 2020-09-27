#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,M,x,y,Q;
    cin>>N>>M;
    pair<int,int> p1,p2;
    vector<pair<int,int> > v1;
    for(int i=0;i<M;i++)
    {
        cin>>x>>y;
        p1 = make_pair(x,y);
        v1.push_back(p1);
    }
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        cin>>x>>y;
        p1 = make_pair(x,y);
        p2 = make_pair(y,x);
        if(find(v1.begin(),v1.end(),p1)!=v1.end() || find(v1.begin(),v1.end(),p2)!=v1.end())
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }            
    }
    return 0;
}