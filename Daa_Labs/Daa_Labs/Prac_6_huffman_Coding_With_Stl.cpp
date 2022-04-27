#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
	public:
		TreeNode* left;
		TreeNode* right;
		char data;
		TreeNode(char c)
		{
			data = c;
				left = right = NULL;
		}	
		TreeNode()
		{
			left = right = NULL;
		}
};
void rec(TreeNode* root,string temp,unordered_map<char,string> &help)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->right==NULL && root->left==NULL)
	{
		help[root->data] = temp;
		return ;
	}
	string left,right;
	left = temp;
	right = temp;
	left.push_back('0');
	right.push_back('1');
	rec(root->left,left,help);
	rec(root->right,right,help);
}
int main()
{
	cout<<"Please enter the encoded string : ";
	string str;
	getline(cin,str);
	unordered_map<char,int> maap;
	TreeNode* root = NULL;
	for(int i = 0 ; i<str.length();i++)
	{
		maap[str[i]]+=1;		
	}
	vector<pair<int,char>> help;
	for(auto it = maap.begin();it!=maap.end();it++)
	{
		help.push_back({it->second,it->first});
	}
	sort(help.rbegin(),help.rend());
	
	for(int i = 0 ;i<help.size();i+=2)
	{
		char first = help[i].second;
		if(i+1==help.size())
		{
			TreeNode* g = new TreeNode();
			TreeNode* l1 = new TreeNode(first);
			if(root==NULL)
			{
				g->right = l1;
				root = g;	
			}
			else
			{
				g->left = l1;
				g->right = root;
				root = g;	
			}	
		}	
		else
		{
			char second = help[i+1].second;
			TreeNode* temp = new TreeNode();
			TreeNode* l1 = new TreeNode(first);
			TreeNode* l2 = new TreeNode(second);
			temp->left  =  l2;
			temp->right =  l1;
			if(root==NULL)
			{
				root = temp;
			}
			else
			{
				TreeNode* tem  = new TreeNode();
				tem->right = root;
				tem->left = temp;
				root = tem; 
			}
		} 
	}
	unordered_map<char,string> helper;
	rec(root,"",helper);
	cout<<"Decoded string is : ";
	for(int i = 0 ; i<str.length();i++)
	{
		cout<<helper[str[i]];
	}
	cout<<endl;
	cout<<endl<<"mapping of each character is : \n";
	for(auto it = helper.begin();it!=helper.end();it++)
	{
		cout<<it->first<<" - "<<it->second<<endl;
	}
	return 0;
}