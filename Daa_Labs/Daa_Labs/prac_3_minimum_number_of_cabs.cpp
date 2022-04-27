#include<bits/stdc++.h>
using namespace std;



// Enter the time in H1:M1 Format
//starting time as 12:30
//ending time as 13:30
 
// H>=0 && H<=23
//M>=0 && M<=59

//starttime is always smaller than equal to endtime


/*
sample input

6
1 0 2 0
16 0 21 30
9 30 13 0
21 30 22 30
21 30 22 30
12 0 12 30
*/
int main()
{
	int n;
	cin>>n;
	int tot_min = 24*60;
	int timeline[tot_min];
	for(int i = 0; i<=tot_min;i++)
	{
		timeline[i] = 0;
	}
	for(int i = 0; i<n;	i++)
	{
		int h1,m1,h2,m2;
		cin>>h1>>m1>>h2>>m2;
		h1*=60;
		h2*=60;
		h1+=m1;
		h2+=m2;
		for(int k = h1;k<=h2;k++)
		{
			timeline[k]+=1;
		}
	}
	int ans = 0;
	for(int i = 0;i<tot_min;i++)
	{
		ans = max(ans,timeline[i]);
	}
	cout<<ans<<endl;
	return 0;
}