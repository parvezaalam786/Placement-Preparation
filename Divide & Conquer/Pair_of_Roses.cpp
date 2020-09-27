#include<bits/stdc++.h>
using namespace std;

int main(){
    string blank;
    int T,N,a,b,M;
    cin>>T;
    while(T--){
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        cin>>M;
        sort(arr,arr+N);
        int diff = INT_MAX;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(arr[i]+arr[j]==M){
                    int d = abs(arr[i]-arr[j]);
                    if(d<diff){
                        diff = d;
                        a = arr[i];
                        b = arr[j];
                    }
                }
            }
        }
        cout<<"Deepak should buy roses whose prices are "<<a<<" and "<<b<<"."<<endl; 
        
        
        getline(cin,blank);
    }
    return 0;
}