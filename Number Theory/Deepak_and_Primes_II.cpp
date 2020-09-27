#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		long long int a,b;
		cin>>a>>b;
		long long int pp[1000000];
		fill(pp,pp+1000000,1);
		long long int n=sqrt(b);
		long long int p[n+1];
		fill(p,p+n+1,1);
		for(long long int i=2;i*i*i*i<=b;i++){
			if(p[i]){
				for(long long int j=2*i;j*j<=b;j+=i){
					p[j]=0;
				}
		    }
		}
		for(long long int i=2;i*i<=b;i++){
			if(p[i]){
				for(long long int j=a;j<=b;){
					if(j>i&&j%i==0){
					    
					        pp[j-a]=0;
					    j+=i;
					}
					else
					j++;
				}
			}
		}
		
		long long int x=(a==1)?2:a;
		for(long long int i=x;i<=b;i++){
			//cout<<pp[i-1]<<" ";
			if(pp[i-a])
			cout<<i<<endl;
		}
		if(t!=0)
		cout<<endl;
	}
	// your code gfor(oes here
	return 0;
}