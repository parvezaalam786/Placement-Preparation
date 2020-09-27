#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
int maxSubArray(int arr[],int n){
    int sum1 = INT_MIN,sum2 = 0;
    for(int i=0;i<n;i++){
        sum2 = sum2+arr[i];
        if(sum2>sum1)
            sum1 = sum2;
        if(sum2<0)
            sum2 = 0;    
    }
    return sum1;
}
int maxSubSeq(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>0)
            sum += arr[i];
    }
    if(sum==0)
        sum = *max_element(arr,arr+n);
    return sum;
}
int main()
{
    fast_io;
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int sum1 = maxSubArray(arr,n);
        int sum2 = maxSubSeq(arr,n);
        cout<<sum1<<" "<<sum2<<endl;    
    }
    return 0;
}