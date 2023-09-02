// directed graph
// convert adjacency list to adjacency matrix
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
int adjMat[N][N];

int main()
{
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v; cin>>u>>v;
        adjList[u].push_back(v);
    }

    /* represantation of adjacent list */

    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<i<<" : ";
    //     for(int v: adjList[i]){
    //         cout<<v<<" ";
    //     }
    //     cout<<endl;
 
    // }

    /* conversion of adjacent list to adjcent matrix */
    for (int i = 1; i <= n; i++)
    {
        for(int v: adjList[i]){
            adjMat[i][v] = 1;
        }
    }

    /* represantation of adjacent matrix */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


// input -----> 
// 3
// 5
// 1 2
// 2 3
// 1 3
// 3 1
// 3 2