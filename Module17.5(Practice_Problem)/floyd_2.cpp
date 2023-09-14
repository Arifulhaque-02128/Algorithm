#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+9;

int main()
{
    int n; cin>>n;
    int dist[n+1][n+1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val; cin>>val;
            if(val == -1) dist[i][j] = INF;
            else dist[i][j] = val;
        }
    }

    // floyd-warshall algorithm

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int max_cost = -1;

    // print the dist matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dist[i][j] == INF) continue;
            if(dist[i][j] > max_cost) max_cost = dist[i][j];
        }
    }

    cout<<max_cost<<endl;
    

    
    return 0;
}