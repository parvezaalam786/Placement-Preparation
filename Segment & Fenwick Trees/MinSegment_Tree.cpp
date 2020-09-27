#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
    
int arr[100005];
int tree[400005];

int query(int ss,int se,int qs,int qe,int index)
{
    if(ss>=qs&&se<=qe) return tree[index];

    if(qe<ss||qs>se) return INT_MAX;

    int mid = (ss+se)/2;
    int leftAns = query(ss,mid,qs,qe,2*index);
    int rightAns = query(mid+1,se,qs,qe,2*index+1);

    return min(leftAns,rightAns);
}

void buildTree(int s,int e,int index)
{
    if(s==e)
    {
        tree[index] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    buildTree(s,mid,2*index);
    buildTree(mid+1,e,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

void updateNode(int ss,int se,int i,int increment,int index)
{
    if(i>se||i<ss)
    {
        return;
    }
    if(ss==se)
    {
        tree[index] = increment;
        return ;
    }
    int mid = (ss+se)/2;
    updateNode(ss,mid,i,increment,2*index);
    updateNode(mid+1,se,i,increment,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

void updateRange(int ss,int se,int l,int r,int inc,int index)
{
    if(l>se||r<ss)
        return;
    if(ss==se)
    {
        tree[index] += inc;
        return;
    }
    int mid = (ss+se)/2;

    updateRange(ss,mid,l,r,inc,2*index);
    updateRange(mid+1,se,l,r,inc,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}

int main()
{
    fast_io;
    //input;
    //output;

    int n,Q;   
    cin>>n>>Q;
    for(int i=0;i<n;i++) cin>>arr[i];
    buildTree(0,n-1,1);

    for(int i=0;i<Q;i++)
    {
        int a,x,y; cin>>a>>x>>y;
        if(a==1)
        {
            cout<<query(0,n-1,x-1,y,1)<<endl;
        }
        if(a==2)
        {
            updateNode(0,n-1,x-1,y,1);
        }
    }
    // updateRange(0,n-1,3,4,5,1);
    return 0;
}








/*
//hackerblocks solution range min query
#include<bits/stdc++.h>
using namespace std;

void buildTree(int *a,int s,int e,int *tree,int index){
    if(s==e){
        tree[index] = a[s];
        return ;
    }
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}
void updateNode(int *tree,int ss,int se,int i,int value,int index){
    if(i>se||i<ss){
        return ;
    }
    if(ss==se){
        tree[index] = value;
        return ;
    }
    int mid = (ss+se)/2;
    updateNode(tree,ss,mid,i,value,2*index);
    updateNode(tree,mid+1,se,i,value,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return ;
}
int query(int *tree,int ss,int se,int qs,int qe,int index){
    if(ss>=qs&&se<=qe){
        return tree[index];
    }
    if(qe<ss||qs>se){
        return INT_MAX;
    }
    int mid = (ss+se)/2;
    int leftAns = query(tree,ss,mid,qs,qe,2*index);
    int rightAns = query(tree,mid+1,se,qs,qe,2*index+1);
    return min(leftAns,rightAns);
}
int main()
{
    int N,Q;
    cin>>N>>Q;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int tree[4*N+1];
    buildTree(arr,0,N-1,tree,1);
    int a,X,Y;
    for(int i=0;i<Q;i++){
        cin>>a>>X>>Y;
        if(a==1){
            //Min Value
            cout<<query(tree,0,N-1,X-1,Y-1,1)<<endl;
        }
        else{
            //Update
            updateNode(tree,0,N-1,X-1,Y,1);
        }
    }
    return 0;
}
*/