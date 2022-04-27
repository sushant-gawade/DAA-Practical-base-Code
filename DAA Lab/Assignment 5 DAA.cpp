/*Design & Implement Prims Algorithm using Greedy Approach. 
Calculate the time complexity of the algorithm.*/
#include <cstring>
#include <iostream>
using namespace std;

class Prims
{
public:
    int graph[10][10];
    int v,no_edge,cost_path;
    int V1;

    Prims()
    {
        cost_path=0;
        no_edge=0;
    }

    void inputGraph();
    void displaygraph();
    void minCost();
};
//input graph
void Prims::inputGraph()
{
    cout<<"\n Plese Enter The Number of Vertices in Graph: ";
    cin>>V1;
    v=V1;
    cout<<"\nEnter The Adjacency Matrix :"<<endl;
    for(int i=0;i<V1;i++)
    {
        for(int j=i;j<V1;j++)
        {
            if(i==j)
			{
				graph[i][j]=0;
			}
			else
			{
				cout<<"\nWeight of the matrix from ("<<i<<" to "<<j<<"): ";
				cin>>graph[i][j];
				graph[j][i]=graph[i][j];
			}
        }
    }
}
//display
void Prims::displaygraph()
{
	cout<<endl;
	for(int i=0;i<V1;i++)
    {
        for(int j=0;j<V1;j++)
        {
    		cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
}
//Finding minimum cost
void Prims::minCost()
{
    int selected[v];
    //predfine function
    memset(selected, false, sizeof(selected));
    
	selected[0] = true;
	cout<<"\n********\n";
    cout<<"Edge " << " : " <<"Weight "<<endl;
	cout<<"\n********\n";
    int x,y;
    while (no_edge < V1 - 1) {

        int min = 9999999;
        x = 0;
        y = 0;

        for (int i = 0; i < V1; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V1; j++)
                {
        
                    if (!(selected[j]) && graph[i][j])
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << graph[x][y];
        cout << endl;
        cost_path = cost_path + graph[x][y];
        selected[y] = true;
        no_edge++;
    }
    cout<<"\n********\n";
    cout<<"\n\nMinimum Cost of Path Using Prims Algorithm : " << cost_path;

}

int main()
{
    Prims sushant;
    int a=1;
    while(a==1)
    {
        sushant.inputGraph();
        sushant.displaygraph();
        sushant.minCost();
        cout<<"\n\nDo You Want to Continue? Press 1 Else 0: ";
        cin>>a;
    }
    return 0;
}
