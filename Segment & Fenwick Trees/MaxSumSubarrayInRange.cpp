#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long
#define pb push_back
const int inf  = 1e9;
#define mod 1000000007

const int maxn = 50010;

struct treeNode
{
    int preSum;
    int sufSum;
    int sum;
    int maxSum;
};
int arr[maxn];
treeNode tree[4 * maxn + 1];

void build(int s, int e, int idx)
{
    if (s == e)
    {
        tree[idx] = ((treeNode) {arr[s], arr[s], arr[s], arr[s]});
    }
    else
    {
        int mid = (s + e) / 2;
        build(s, mid, 2 * idx);
        build(mid + 1, e, 2 * idx + 1);

        treeNode left = tree[2 * idx];
        treeNode right = tree[2 * idx + 1];

        tree[idx].preSum = max(left.preSum, left.sum + right.preSum);
        tree[idx].sufSum = max(right.sufSum, left.sufSum + right.sum);
        tree[idx].sum = left.sum + right.sum;
        tree[idx].maxSum = max(left.sufSum + right.preSum, max(left.maxSum, right.maxSum));
    }
}

treeNode maxSumQuery(int s, int e, int qs, int qe, int idx)
{
    if (s >= qs and e <= qe)
        return tree[idx];
    if (qs > e or qe < s)
    {
        return ((treeNode) { -inf, -inf, -inf, -inf});
    }
    int mid = (s + e) / 2;

    treeNode left = maxSumQuery(s, mid, qs, qe, 2 * idx);
    treeNode right = maxSumQuery(mid + 1, e, qs, qe, 2 * idx + 1);

    treeNode temp;
    temp.preSum = max(left.preSum, left.sum + right.preSum);
    temp.sufSum = max(right.sufSum, left.sufSum + right.sum);
    temp.sum = left.sum + right.sum;
    temp.maxSum = max(left.sufSum + right.preSum, max(left.maxSum, right.maxSum));

    return temp;
}


void solve()
{
    int n, q, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(0, n - 1, 1);
    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        x--; y--;
        cout << maxSumQuery(0, n - 1, x, y, 1).maxSum << "\n";
    }

}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
