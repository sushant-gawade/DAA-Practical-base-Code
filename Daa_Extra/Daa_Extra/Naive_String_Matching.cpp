#include<iostream>
using namespace std;
int main()
{
	string str,pattern;
	cout<<"Enter the String -> ";
	cin>>str;
	cout<<"Enter the Pattern -> ";
	cin>>pattern;
	bool check  = true;
	int store[str.length()];
	int ind = 0;
	for(int i = 0; i+pattern.length()-1<str.length();i++)
	{
		string temp;
		int j = i;
		int len = pattern.length();
		while(len>0)
		{
			temp.push_back(str[j]);
			j+=1;
			len-=1;
		}
		if(temp==pattern)
		{
			check = false;
			store[ind] = i;
			ind+=1;
		}
	}
	if(check)
	{
		cout<<"No Pattern Founded"<<endl;
	}
	else
	{
		cout<<"Patterns Are Founded At These Indices "<<endl;
		for(int i = 0;i<ind;i++)
		{
			cout<<store[i]<<" ";
		}
		
	}
}