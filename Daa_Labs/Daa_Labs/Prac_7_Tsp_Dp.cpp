#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
void tsp(int curr,int cost,int temp[],int size,int &ans)
{
	if(size==1)
	{
		cost+=dp[curr][temp[0]];
		cost+=dp[temp[0]][0];
		ans = min(cost,ans);
		return ;
	}
	for(int i = 0;i<size;i++)
	{
		int t1[1001];
		int l = 0;
		for(int j = 0 ;j<size;j++)
		{
			if(i!=j)
			{
				t1[l] = temp[j];
				l+=1;
			}
		}
		tsp(temp[i],cost+dp[curr][temp[i]],t1,size-1,ans);	
	}
}
int main()
{
	int nodes;
	cout<<"Enter the number of nodes -> ";
	cin>>nodes;
	for(int i = 0;i<=1000;i++)
	{
		for(int j = 0;j<=1000;j++)
		{
			dp[i][j] = 0;
		}
	}
	for(int i = 0; i<nodes;i++)
	{
		for(int j = 0;j<nodes;j++)
		{
			if(i==j)
			{
				continue;
			}
			cout<<"Enter the distance between "<<i+1<<" to "<<j+1<<" -> ";
			cin>>dp[i][j];
		}
	}
	int ans = INT_MAX;
	int temp[nodes];
	for(int i = 1;i<nodes;i++)
	{
		temp[i-1] = i;
	}
	tsp(0,0,temp,nodes-1,ans);
	cout<<"\n The Minimum cost is "<<ans;
}