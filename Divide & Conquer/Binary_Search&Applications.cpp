#include<iostream>
using namespace std;
int BinarySearch(int arr[],int n,int ele)/// Complexity O(logn)
{
	int s=0,end=n-1,mid;
	while(s<=end)
	{
		mid=(s+end)/2;
		if(arr[mid]==ele)
			{
				return mid;
			}
		else if(arr[mid]>ele)
		{
			end=mid-1;
		}
		else
			s=mid+1;
	}
	return -1;
}
int FirstOccurence(int arr[],int n,int ele) /// complexity is O(logn)
{
	int s=0,end=n-1,mid;
	int ans=-1;
	while(s<=end)
	{
		mid=(s+end)/2;
		if(arr[mid]==ele)
		{
			ans=mid;
			end=mid-1;
		}
		else if(arr[mid]>ele)
		{
			end=mid-1;
		}
		else if(arr[mid]<ele)
		{
			s=mid+1;
		}
	}
	return ans;
}
int LastOccurence(int arr[],int n,int ele) ///complexity is O(logn)
{
	int s=0,end=n-1,mid;
	int ans=-1;
	while(s<=end)
	{
		mid=(s+end)/2;
		if(arr[mid]==ele)
		{
			ans=mid;
			s=mid+1;
		}
		else if(arr[mid]>ele)
		{
			end=mid-1;
		}
		else if(arr[mid]<ele)
		{
			s=mid+1;
		}
	}
	return ans;
}
float SquareRoot(int n,int place)  /// Complexity is O(logn + places)
{
	int s=1,end=n,mid;
	float ans;
	/// Integer part
	while(s<=end)
	{
		mid=(s+end)/2;
		if(mid*mid==n)
		{
			ans=mid;
			break;
		}
		else if(mid*mid<n)
		{
			s=mid+1;
			ans=mid;
		}
		else if(mid*mid>n)
		{
			end=mid-1;
		}
	}
	float increment = 0.1;
	for(int i=0;i<place;i++)
	{
		while(ans*ans<=n)
		{
			ans+=increment;
		}
		///the loop fails when ans*ans>n
		ans=ans-increment;
		increment=increment/10;
	}
return ans;
}

int main()
{
	int arr[]={1,1,1,4,5,6,7,8,9,9,9,10};
	int n=sizeof(arr)/sizeof(int);
	//int index=BinarySearch(arr,n,4);
	int index=FirstOccurence(arr,n,9);
	cout<<index;
	// int index=LastOccurence(arr,n,9);
	// if(index==-1)
	// 	cout<<"Element is not found"<<endl;
	// else
	// 	cout<<"ELement is found at index "<<index<<endl;
	cout<<"Square root of 4 :"<<SquareRoot(5,2);
	return 0;
}
