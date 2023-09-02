// directed graph
// convert adjacency matrix to adjacency list
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
int adjMat[N][N];

int main()
{
    int n; cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w; cin>>w;
            adjMat[i][j] = w;
        }
    }

    /* represantation of adjacent matrix */

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout<<adjMat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    /* conversion of adjacent matrix to adjcent list */

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(adjMat[i][j] != 0){
                adjList[i].push_back(j);
            }
        }
    }

    /* represantation of adjacent list */

    for (int i = 1; i <= n; i++)
    {
        cout<<"List "<<i<<" : ";
        for(int v: adjList[i]){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


// input -----> 4
// 0 0 0 1
// 1 0 0 1
// 1 1 0 0
// 0 0 1 0

// input -----> 5
// 0 0 0 0 0
// 1 0 0 1 1
// 1 1 0 1 1
// 1 1 1 0 0
// 0 0 1 0 0
