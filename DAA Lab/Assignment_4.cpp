#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

auto start = high_resolution_clock::now();

void fillTable(const vector<int>& coins,int amt,vector<vector<int>>& table)
{
	for(int i=0;i<coins.size();i++)
	{
		table[i].resize(amt);
		for(int j=1;j<=amt;j++)
		{
			if(i==0)
			{
				table[i][j-1]=j;
			}
			else
			{

					int rem = j % coins[i];
					int div = j / coins[i];
					
					
					int remcoin = (rem == 0 )?0:table[i-1][rem-1];
					table[i][j-1] = div + remcoin;
			
				
			}
		}
	}
}
void printCombination(int amt, const std::vector<int>& coins)
{
	
	cout<<"\nCombination is : ";
	for(int i=coins.size()-1;i>=0;i--)
	{
		int ncoins = amt / coins[i];
		amt = amt % coins[i];
		
		cout<< "\n(" << ncoins << "*" << coins[i] <<")\t";
			
	}
}
void printTable(vector<vector<int>>& table, const vector<int>& coins)
{
	cout << "\t" ;
	for(int i=1;i<=table[0].size();i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	
	for(int i=0;i<table.size();i++)
	{
		cout << coins[i] << "\t" ;
		for(int j=0;j<table[i].size();j++)
		{
			cout<<table[i][j]<<"\t";
		}
		cout<<endl;
	}
}
int main()
{
	const vector<int> coins={1,2,5,10};
	vector<vector<int>> table;
	table.resize(coins.size());
	int amount=0;
	cout<<"Enter the amount: ";
	cin>>amount;
	
	
	fillTable(coins,amount,table);
	printTable(table,coins);
	
	cout << "\nMinimum coins required : " << table[coins.size()-1][amount-1];
	printCombination(amount,coins);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout <<"Time taken is:" <<duration.count()/1000000 <<" seconds"<< endl;
	
return 0;	
}
