#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9+9;
const int N = 1005;
vector<pii> g[N];
int dist[N];
int n, m;

void bellman_ford(int src){
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int i = 1; i < n; i++)
    {
        // relax distance from every node
        for(int u=1; u<=n ; u++){
            for(pii vpair:g[u]){
                int v = vpair.first;
                int w = vpair.second;

                if(dist[u] != INF && dist[v] > dist[u] + w ){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}
 
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        g[u].push_back({v, w});
    }

    int src; cin>>src;
    bellman_ford(src);

    for(int i=1; i<=n; i++){
        cout<<"distance for "<<i<<" - "<<dist[i]<<endl;
    }

    return 0;
}

// input ---->4 5
// 1 2 5
// 1 3 10
// 2 4 -2
// 2 3 -1
// 4 3 3
// 1