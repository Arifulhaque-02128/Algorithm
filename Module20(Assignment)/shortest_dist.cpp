//https://www.hackerrank.com/contests/assignment-04-a-long longroduction-to-algorithms-a-batch-03/challenges/shortest-distance-2

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
const int INF = 1e8;
long long g[N][N];


void floyd_warshall(int n){
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], (g[i][k] + g[k][j]));
            }
        }
    }
}

int main()
{

    int n, m; cin>>n>>m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }

    while (m--)
    {
        int u, v;
        long long w; 
        cin>>u>>v>>w;
        g[u][v] = min(g[u][v], w);
    }

    floyd_warshall(n);

    long long t; cin>>t;
    while (t--)
    {
        int src, des; cin>>src>>des;
        if(g[src][des] == INF) cout<<-1<<endl;
        else cout<<g[src][des]<<endl;
    }

    return 0;
}


// input ----> 4 7
// 1 2 10
// 2 3 5
// 3 4 2
// 4 2 3
// 3 1 7
// 2 1 1
// 1 4 4
// 6
// 1 2
// 4 1
// 3 1
// 1 4
// 2 4
// 4 2


// input ----> 4 4
// 1 2 4
// 2 3 4
// 3 1 2
// 1 2 10
// 6
// 1 2
// 2 1
// 1 3
// 3 1
// 2 3
// 3 2