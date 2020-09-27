#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
int arr[100005];
vector<int> tree[400005];

vector<int> merge(vector<int>& v1,vector<int>& v2)
{
    int i=0,j=0;
    vector<int> v;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]<=v2[j])
        {
            v.push_back(v1[i]);
            i++;
        }
        else
        {
            v.push_back(v2[j]);
            j++;
        }
    }
    for(int k=i;k<v1.size();k++)
        v.push_back(v1[k]);
    for(int k=j;k<v2.size();k++)
        v.push_back(v2[k]);
    return v;
}

void buildTree(int s,int e,int index)
{
    if(s==e)
    {
        tree[index].push_back(arr[s]);
        return;
    }
    int mid = (s+e)/2;
    buildTree(s,mid,2*index);
    buildTree(mid+1,e,2*index+1);
    tree[index] = merge(tree[2*index],tree[2*index+1]);
}

int query(int s,int e,int l,int r,int index,int k)
{
    if(r<s||l>e)
        return 0;
    
    if(s>=l && e<=r)
    {
        return (tree[index].size() - (lower_bound(tree[index].begin(),tree[index].end(), k) - tree[index].begin())); 
    }
    int mid = (s+e)/2;

    return (query(s,mid,l,r,2*index,k)+query(mid+1,e,l,r,2*index+1,k));
}
int main()
{
    int N; cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    int index = 1,ss = 0, se = N-1;
    buildTree(ss,se,index);

    int Q;  cin>>Q;
    for(int i=0;i<Q;i++)
    {
        int L,R,K;
        cin>>L>>R>>K;
        cout<<query(ss,se,L-1,R-1,index,K)<<endl;
    }
    return 0;
}