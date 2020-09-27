#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#define int long long 
#define endl "\n"
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1e16
const double pi = 3.141592653589793238460;
#define debug false
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007 

int lazy[4*100010+10]  = {0};
//int arr[100010] = {0};
int tree[4*100010+10] = {0};

void buildTree(int *a,int s,int e,int *tree,int index){
    
    if(s==e){
        tree[index] = a[s];
        return ;
    }
    
    //Rec case
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index] = (tree[2*index]+tree[2*index+1]);
    
    return;
}

void updateRangeLazy(int *tree,int ss,int se,int l,int r,int inc,int index){
    //First Step - Never we go down if you have lazy value at node, first resolve it 
    
    if(lazy[index]!=0){
        
        tree[index] += (se-ss+1)*lazy[index];
        
        //if not a leaf node 
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    // Out of Bounds 
    if(ss>r || l > se){
        return;
    }
    // Complete Overlap- Beeche Raste Mei
    if(ss>=l && se<=r){
        tree[index] += (se-ss+1)*inc;
        
        // Pass the lazy value to children if they are not leaf
        if(ss!=se){
            lazy[2*index] +=  inc;
            lazy[2*index+1] += inc;
        }
        return ;
    }

    int mid = (ss+se)/2;
    updateRangeLazy(tree,ss,mid,l,r,inc,2*index);
    updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index] = (tree[2*index]+tree[2*index+1]);
    return;
}

int queryLazy(int *tree,int ss,int se,int qs,int qe,int index)
{
    //Never go downn if we have lazy value at node, first resolve it
    if(lazy[index]!=0)
    {
        tree[index] += (se-ss+1)*lazy[index];

        // if not a leaf node
        if(ss!=se)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];    
        }
        lazy[index] = 0;
    }

    // No overlap
    if(ss>qe || se<qs)
    {
        return 0;
    }
    // Complete overlap
    if(ss>=qs && se<=qe)
    {
        return tree[index];
    }

    // Partial
    int mid = (ss+se)/2;
    int left = queryLazy(tree,ss,mid,qs,qe,2*index);
    int right = queryLazy(tree,mid+1,se,qs,qe,2*index+1);

    return (left+right);

}

void solve()
{
 	int T;
 	cin>>T;
 	while(T--)
 	{
 		int N,Q;
 		cin>>N>>Q;
 		memset(lazy,0,sizeof(lazy));
 		//memset(arr,0,sizeof(arr));
 		memset(tree,0,sizeof(tree));
 		//buildTree(arr,0,N-1,tree,1);
 		int p,q,v,x;
 		while(Q--)
 		{
 			cin>>x;
 			if(x==0)
 			{
 				cin>>p>>q>>v;
 				updateRangeLazy(tree,0,N-1,p-1,q-1,v,1);
 			}
 			else
 			{
 				cin>>p>>q;
 				cout<<queryLazy(tree,0,N-1,p-1,q-1,1)<<"\n";
 			}
 		}
 	}
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        // freopen("Test.txt","r",stdin);
        // freopen("Output.txt","w",stdout);
    #endif
    
     // if(debug){watch_is();}
    solve();   
    return 0;
}