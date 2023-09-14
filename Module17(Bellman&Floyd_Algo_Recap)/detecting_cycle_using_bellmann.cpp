#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1005;
const int INF = 1e9+5;
vector<pii> g[N];
int dist[N];

int n, m; 
bool cycleExist = false;

void bellman_ford(int src){
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }

    dist[src] = 0;

    for(int i = 1; i<=n; i++){
        for(int u=1; u<=n; u++){
            for(pii vpair:g[u]){
                int v = vpair.first;
                int w = vpair.second;

                if(dist[u] != INF && dist[v] > dist[u] + w){
                    if(i == n){
                        cycleExist = true;
                        break;
                    }
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main() {

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        g[u].push_back({v, w});
    }

    int src; cin>>src;

    bellman_ford(src);

    if(cycleExist) cout<<"Cycle Exist."<<endl;
    else{
        cout<<"No Cycle Exist."<<endl;
        for (int i = 1; i <= n; i++)
        {
            cout<<"Distance from "<<i<<" - "<<dist[i]<<endl;
        }
    }

    return 0;
}


// input ----> 4 5 
// 1 2 4
// 1 3 5
// 2 3 2
// 3 4 3
// 4 2 -10
// 1


// input ----> 4 4
// 1 2 4
// 1 3 5
// 3 4 3
// 4 2 -10
// 1