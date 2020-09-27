#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   for(int i=0;i<n;i++)
      cin>>arr[i];
   int l=0,r=0,L=0,R=0;
   int cnt0 = 0;
   int ans = 0;
   
   while(r<n)
   {
      if(arr[r]==1)
         r++;
      else if(arr[r]==0)
      {
         cnt0++;
         r++;
      }
      while(cnt0>k)
      {
         if(arr[l]==0)
         {
            cnt0--;
            l++;
         }
         else if(arr[l]==1)
            l++;
      }
      if(ans<(r-l))
      {
         ans = r-l;
         L = l;
      }
   }
   
   for(int i=L;i<L+ans;i++)
      arr[i] = 1;
   cout<<ans<<endl;
   for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
   cout<<"\n";
   
   return 0;
}