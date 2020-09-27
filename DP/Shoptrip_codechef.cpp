#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 1000000000
#define N 50

// Euclidean distance
long double distance(pair<int,int> p1,pair<int,int> p2)
{
    int dx = p1.first-p2.first;
    int dy = p1.second-p2.second;
    return sqrt(dx*dx+dy*dy);
}

long double dist[N][N] = {0};
long double dp[1<<13][N];

// n is the number of shops except kitchen , k is the total number of ingredients needed
int n,k;

vector<pair<int,int> > coordinates;
vector<int> ingredients;

long double shopTrip(int mask,int idx)
{
    // Base case
    if((mask==(1<<k)-1)&&idx==0)
    {
        return 0;
    }
    if(dp[mask][idx]!=-1)
    {
        return dp[mask][idx];
    }
    dp[mask][idx] = INT_MAX;
    for(int i=0;i<=n;i++)
    {
        if((mask|ingredients[i])!=mask||(i==0))
        {
            dp[mask][idx] = min(dp[mask][idx],dist[idx][i]+shopTrip(mask|ingredients[i],i));
        }
    }
    return dp[mask][idx];
}

int main()
{
    int T;
    string temp;
    cin>>T;
    
    while(T--)
    {
        cin>>n>>k;
        coordinates.clear();
        ingredients.clear();

        coordinates.push_back({0,0});
        for(int i=0;i<n;i++)
        {
            int x,y; cin>>x>>y;
            coordinates.push_back({x,y});
        }
        // Read one string one for each shop
        ingredients.push_back(0);

        int possible = 0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            reverse(temp.begin(),temp.end());

            int temp_mask = 0;
            for(int j=0;j<temp.length();j++)
            {
                temp_mask |=(1<<j)*(temp[j]-'0');
            }
            possible |= temp_mask;
            ingredients.push_back(temp_mask);
        }
        int ALL = ((1<<k)-1);
        if(possible!=ALL)
        {
            cout<<"-1"<<"\n";
            continue;
        }

        // Distance array
        memset(dist,0,sizeof(dist));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dist[i][j] = distance(coordinates[i],coordinates[j]);
            }
        }
        for(int i=0;i<(1<<k);i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j] = -1;
            }
        }
        long double ans = shopTrip(0,0);
        cout<<fixed<<setprecision(9)<<ans<<"\n";

    }
    return 0;
}