//greedy method
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size;
	cout<<"Enter the size -> ";
	cin>>size;
	int arr[size+1];
	for(int i = 0;i<size;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+size);
	int cost;
	cout<<"Enter the cost you want -> ";
	cin>>cost;
	int coins[size+1];
	int sz = 0;
	int minimumcoins = 0;
	
	for(int  i = size-1;i>=0;i--)
	{
		while(cost>=arr[i])
		{
			cost-=arr[i];
			minimumcoins+=1;
			coins[sz] = arr[i];
			sz+=1;
		}
	}
	if(cost==0)
	{
		cout<<"Minimum Coins Required Are -> "<<minimumcoins<<endl;
	
		for(int i = 0; i<sz;i++)
		{
			cout<<coins[i]<<" -> ";
		}
	}
	else
	{
		cout<<"Not possible to get solution using greedy method"<<endl;
	}
	return 0;
}