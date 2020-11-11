/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
#define deb(x) cout<<#x<<" = "<<x
#define all(x) (x).begin(),(x).end()
/*
Given a dictionary of distinct words and an M x N board where every cell has one character.
Find all possible words from the dictionary that can be formed by a sequence of adjacent
characters on the board. We can move to any of 8 adjacent characters, but a word should not
have multiple instances of the same cell
*/

const int N = 3;
const int M = 3;
set<string> dictionary;
int n = 4;

bool isWord(string &str)
{
	if (dictionary.count(str))
		return true;
	return false;
}

void findWord(char boggle[M][N], bool visited[M][N], int i, int j, string& str)
{
	visited[i][j] = true;
	str = str + boggle[i][j];

	if (isWord(str))
		cout << str << "\n";
	for (int row = i - 1; row <= i + 1 and row < M; row++)
	{
		for (int col = j - 1; col <= j + 1 and col < N; col++)
		{
			if (row >= 0 and col >= 0 and !visited[row][col])
				findWord(boggle, visited, row, col, str);
		}
	}
	str.pop_back();
	visited[i][j] = false;
}


void solve()
{
	char boggle[M][N] =
	{	{ 'G', 'I', 'Z' },
		{ 'U', 'E', 'K' },
		{ 'Q', 'S', 'E' }
	};

	dictionary.insert("GEEKS");
	dictionary.insert("FOR");
	dictionary.insert("QUIZ");
	dictionary.insert("GO");
	cout << "Following words of dictionary are present\n";
	bool visited[M][N];
	memset(visited, false, sizeof(visited));
	string str = "";

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			findWord(boggle, visited, i, j, str);
		}
	}

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
