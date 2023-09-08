#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
const int INF = 1e9+5;
int dist[N][N];

int n, m;

void dist_initialization(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == j) dist[i][j] = 0;

            else dist[i][j] = INF;
        }
    }
}

void print_matrix(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dist[i][j] == INF) cout<<"X ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floyd_warshall(){
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j<= n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    dist_initialization();

    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        dist[u][v] = w;
    }

    floyd_warshall();
    
    print_matrix();
    
    return 0;
}