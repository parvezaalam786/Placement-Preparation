#include<bits/stdc++.h>
using namespace std;

int maxAreahistogram(int arr[],int n)
{
	stack<int> s;
	int i=0;
	int area = 0, maxarea = 0;
	int tp = 0;
	while(i<n)
	{
		if(s.empty() || arr[i]>=arr[s.top()])
		{
			s.push(i);
			i++;
		}
		else
		{
			tp = s.top();
			s.pop();
			if(s.empty())
			{
				area = arr[tp]*i;
			}
			else
			{
				area = arr[tp]*(i-s.top()-1);
			}	
			if(area>maxarea)
				maxarea = area;		
		}		
	}
	while(s.empty()==false)
	{
		tp = s.top();
		s.pop();
		if(s.empty())
		{
			area = arr[tp]*i;
		}
		else
		{
			area = arr[tp]*(i-s.top()-1);
		}
		if(area>maxarea)
			maxarea = area;
	}
	return maxarea;
}


int maxfieldArea(int arr[][1010],int r,int c)
{
	int area = 0,maxarea = 0;

	int temp[c];
	maxarea = maxAreahistogram(arr[0],c);
	memset(temp,0,sizeof(temp));
	for(int i=1;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]==0)
				temp[j] = 0;
			else 
				temp[j] += arr[i][j];
		}
		area = maxAreahistogram(temp,c);
		if(maxarea<area)
			maxarea = area;
	}
	return maxarea;
}


int main()
{
	int r,c;
	cin>>r>>c;
	int arr[1010][1010];

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>arr[i][j];
		}
	}

	int ans = maxfieldArea(arr,r,c);
	cout<<ans<<"\n";
	return 0;
}