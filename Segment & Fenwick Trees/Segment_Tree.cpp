// https://ide.codingblocks.com/s/4395

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
#define debug false

// a[] :original array
// s : start index e : end index
// s and e are the indexes of the array whose segment tree is being made
// tree : tree array
// index : tree index

void buildTree(int *a, int s, int e, int *tree, int index)
{
    if (s == e)
    {
        tree[index] = a[s];
        return ;
    }
    int mid = (s + e) / 2;

    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid + 1, e, tree, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return ;
}

int query(int *tree, int s, int e, int qs, int qe, int index)
{
    //Complete overlap
    if (s >= qs && e <= qe)
    {
        return tree[index];
    }
    // No overlap
    if (qe < s || qs > e)
    {
        return inf;
    }

    // Partial Overlap : call on both sides
    int mid = (s + e) / 2;
    int left = query(tree, s, mid, qs, qe, 2 * index);
    int right = query(tree, mid + 1, e, qs, qe, 2 * index + 1);

    return min(left, right);
}


void updateNode(int *tree, int s, int e, int i, int increment, int index)
{
    // Leaf update

    // out of bounds
    if (i > e || i < s)
        return ;

    // reached leaf
    if (s == e)
    {
        tree[index] += increment;
        return;
    }

    // Left and right call

    int mid = (s + e) / 2;
    updateNode(tree, s, mid, i, increment, 2 * index);
    updateNode(tree, mid + 1, e, i, increment, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);

    return;
}

void updateRange(int *tree, int s, int e, int l, int r, int inc, int index)
{
    if (l > e || r < s)
        return ;
    if (s == e)
    {
        tree[index] += inc;
        return ;
    }
    int mid = (s + e) / 2;
    updateRange(tree, s, mid, l, r, inc, 2 * index);
    updateRange(tree, mid + 1, e, l, r, inc, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}


int main()
{
    // fast_io;
    // input;
    // output;
    // if(debug)
    // {
    //     watch_is();
    // }

    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);
    int *tree = new int[4 * n + 1];
    buildTree(a, 0, n - 1, tree, 1);
    // for(int i=1;i<14;i++)
    //     cout<<tree[i]<<" ";
    // cout<<"\n";
    updateNode(tree, 0, n - 1, 3, 10, 1);
    updateRange(tree, 0, n - 1, 2, 3, -15, 1);
    cout << query(tree, 0, n - 1, 0, 5, 1) << "\n";

    return 0;
}