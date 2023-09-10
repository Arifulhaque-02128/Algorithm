// complexity ====> O(v*e) [ v = no. of vertices and e = no. of edges ]
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1005;
vector<pii> adj[N];
int dist[N];

void dist_init(){

    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }
}

void bfs(int src){
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) // O(n)
    {
        int u = q.front();
        q.pop();

        for(pii vpair:adj[u]){  // O(e)
            int v = vpair.first;
            int w = vpair.second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

int main()
{

    int n, e; cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src; cin>>src;

    dist_init();

    bfs(src);

    for (int i = 1; i <= n; i++)
    {
        cout<<src<<" to "<<i<<" minimum cost : ";
        cout<<dist[i]<<endl;
    }
    
    return 0;
}

// input ----:> 7 9
// 1 2 3
// 1 3 5
// 2 3 1
// 2 5 6 
// 3 4 1
// 3 7 12
// 4 6 1 
// 6 5 1 
// 5 7 2
// 1