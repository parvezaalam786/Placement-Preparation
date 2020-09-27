#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define mod 1000000007
#define F first
#define S second
typedef long long ll;
using namespace std;

bool check(int l, int r, int** bit)
{
    r = r+1;
    int* right = new int[26];
    int* left = new int[26];
    memset(right,0,26*sizeof(int));
    memset(left,0,26*sizeof(int));
    while(r>0)
    {
        for(int i = 0; i<=25; i++)
        {
            right[i]+=bit[r][i];
        }
        
        r = r - (r & (-r));
    }
    
    while(l>0)
    {
        for(int i = 0; i<=25; i++)
        {
            left[i]+=bit[l][i];
        }
        
        l = l - (l & (-l));
    }
    
    for(int i = 0; i<=25; i++)
    {
        right[i] = right[i] - left[i];
        //cout<<right[i]<<" ";
    }
    //cout<<endl;
    
    bool odd = false;
    
    for(int i = 0; i<=25; i++)
    {
        if(right[i]%2==1 && !odd)
        {
            odd = true;
        }
        
        else if(right[i]%2==1)
        {
            return false;
        }
    }
    
    return true;
    
}

void update(int index, int** bit, int n, int val)
{
    index = index+1;
    while(index<=n)
    {
        bit[index][val]++;
        index = index + (index & (-index));
    }
}

void updatebit(string& a, int index, int** bit, int n, int newval)
{
    index = index + 1;
    int oldval = a[index-1]-97;
    a[index-1] = (char)(newval+97);
    while(index<=n)
    {
        bit[index][oldval]--;
        bit[index][newval]++;
        index = index + (index & (-index));
    }
    
}

int** construct(string a, int n)
{
    int** bit = new int*[n+1];
    
    for(int i = 0; i < n+1; ++i)
        bit[i] = new int[26];
        
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<26; j++)
        {
            bit[i][j] = 0;
        }
    }
    
    for(int i = 0; i<=a.length()-1; i++)
    {
        update(i,bit,n,a[i]-97);
    }
    
    return bit;
}

int main() 
{
    int n, q, h;
    scanf("%d %d ",&n,&q);
    string a;
    cin>>a;
    
    int** bit = construct(a,n);    
    
    
    for(int i = 1; i<=q; i++)
    {
        scanf("%d ",&h);
        if(h==1)
        {
            int l; char x;
            scanf("%d %c ",&l,&x);
            updatebit(a,l-1,bit,n,x-97);
        }
        
        else
        {
            int l,r;
            scanf("%d %d",&l,&r);
            
            
            if(check(l-1,r-1,bit))
            printf("yes\n");
            
            else printf("no\n");
            
        }
    }
    
    
	return 0;
}