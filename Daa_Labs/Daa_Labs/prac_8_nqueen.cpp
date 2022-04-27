#include<iostream>
using namespace std;
//n queen problem using backtracking
const int m = 100;
bool horizontal(char chessboard[][m],int row,int col,int n)
{
	for(int j = 0;j<n;j++)
	{
		if(chessboard[row][j]!='.')
		{
			return false;
		}
	}
	return true;
} 
bool vertical(char chessboard[][m],int row,int col,int n)
{
	for(int j = 0;j<n;j++)
	{
		if(chessboard[j][col]!='.')
		{
			return false;
		}
	}
	return true;
}
bool daigonal_lower_left(char chessboard[][m],int row,int col,int n)
{
	while(row<n && col>=0)
	{
		if(chessboard[row][col]!='.')
		{
			return false;
		}
		row+=1;
		col-=1;
	}
	return true;
}
bool daigonal_lower_right(char chessboard[][m],int row,int col,int n)
{
	while(row<n && col<n)
	{
		if(chessboard[row][col]!='.')
		{
			return false;
		}
		row+=1;
		col+=1;
	}
	return true;	
}
bool daigonal_upper_right(char chessboard[][m],int row,int col,int n)
{
	while(row>=0 && col>=0)
	{
		if(chessboard[row][col]!='.')
		{
			return false;
		}
		row-=1;
		col-=1;
	}
	return true;
}
bool daigonal_upper_left(char chessboard[][m],int row,int col,int n)
{
	while(row>=0 && col<n)
	{
		if(chessboard[row][col]!='.')
		{
			return false;
		}
		row-=1;
		col+=1;
	}
	return true;
}
void backtracking(int row,int col,int n,char chessboard[][m],int &count)
{
	if(row==n)
	{
		cout<<"Possibility no. "<<count<<endl;
		for(int i = 0; i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{
				cout<<chessboard[i][j];
			}
			cout<<endl;
		}
		count+=1;
		cout<<endl<<endl;
		return ;
	}
	for(int i = col;i<n;i++)
	{
		if(horizontal(chessboard,row,0,n) &&  vertical(chessboard,0,i,n) && daigonal_lower_left(chessboard,row,i,n) && daigonal_lower_right(chessboard,row,i,n) && daigonal_upper_right(chessboard,row,i,n) && daigonal_upper_left(chessboard,row,i,n))	
		{
			chessboard[row][i] = 'q';
			backtracking(row+1,0,n,chessboard,count);
			chessboard[row][i] = '.';
		}
	}
}
int main()
{
	int n;
	cout<<"Enter size of chessboard -> ";
	cin>>n;
	if(n>=1 && n<=10)
	{
		char chessboard[n+1][m];
		for(int i = 0; i<n;i++)
		{
			for(int j = 0 ;j<n;j++)
			{
				chessboard[i][j] = '.';
			}
		}
		int count = 1;
		cout<<endl<<endl;
		backtracking(0,0,n,chessboard,count);		
	}
	else
	{
		cout<<"Value of ChessBoard Should be between 1 to 10 only"<<endl;
	}
	return 0;
}