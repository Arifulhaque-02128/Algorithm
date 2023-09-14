#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 105;
const int M = 10005; 
const int INF = 30000;
vector<pii> g[N];
int dist[N];

int n, m; 

void dist_init(){
    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
    }
}

void bellman_ford(int src){
    dist[src] = 0;
    for (int k = 1; k <= n-1; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for(pii vpair:g[u]){
                int v = vpair.first;
                int w = vpair.second;

                if(dist[u] != INF && dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
       int u, v, w; cin>>u>>v>>w;
       g[u].push_back({v, w}); 
    }

    dist_init();

    bellman_ford(1);

    for (int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }
    
    
    return 0;
}



// input -----> 4 5
// 1 2 10
// 2 3 10
// 1 3 100
// 3 1 -10
// 2 3 1