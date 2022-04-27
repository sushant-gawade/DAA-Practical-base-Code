/*Assume that, There are N Person and each person needs exactly one cab. 
For each person you are given the start time and end time (both inclusive) during which that person will travel. 
Find the Minimum number of cans required. 
Which Strategy will be best suitable to solve this problem.*/
#include<iostream>

using namespace std;

int main()
{
	int size = 1440;
	int tArray[size];
	int strthr,strtmin,endhr,endmin,n;
	
	for(int i=0;i<size;i++){
		tArray[i]=0;
	}
	cout<<"\nEnter number of person : ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"\nEnter the Start and End time (hour minute hour minute) format : ";
		cin>>strthr>>strtmin>>endhr>>endmin;
		
		strtmin=strtmin+(strthr*60);
        endmin=endmin+(endhr*60);
        
        for(int j=strtmin;j<=endmin;j++)
        {
            tArray[j]+=1;
        }
    }
    
    int numberOfCabs=0;
    for(int i=0;i<size;i++)
    {
        numberOfCabs=max(numberOfCabs,tArray[i]);
    }
    cout<<"\nMinimum no of cabs required are:"<<numberOfCabs;
}
