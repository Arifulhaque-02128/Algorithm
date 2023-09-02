#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int adjMat [N][N];

int main()
{
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        adjMat[u][v] = w;
        adjMat[v][u] = w;
    }

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


// input ----> 4
// 5
// 1 2 50
// 1 3 60
// 2 4 70
// 4 3 80
// 3 2 90