// https://www.interviewbit.com/problems/commutable-islands/

#define ppi pair<int,int>
#define ff first
#define ss second
const int maxn = 6e4 + 10;
int par[maxn], Rank[maxn];

int find(int a)
{
	if (par[a] < 0)
		return a;
	return par[a] = find(par[a]);
}
void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (Rank[a] < Rank[b])
	{
		par[a] = b;
		Rank[b] += Rank[a];
	}
	else
	{
		par[b] = a;
		Rank[a] += Rank[b];
	}
}
bool check(int a, int b)
{
	a = find(a);
	b = find(b);
	return (a == b);
}

void Init()
{
	for (int i = 0; i < maxn; i++)
	{
		Rank[i] = 1;
		par[i] = -i;
	}
}


int Solution::solve(int A, vector<vector<int> > &B)
{
	Init();
	priority_queue<pair<int, ppi>, vector<pair<int, ppi>>, greater<pair<int, ppi>>> pq;
	for (auto x : B)
	{
		pq.push({x[2], {x[0], x[1]}});
	}
	int min_cost = 0;
	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();
		if (!check(curr.ss.ff, curr.ss.ss))
		{
			min_cost += curr.ff;
			Union(curr.ss.ff, curr.ss.ss);
		}
	}
	return min_cost;
}
