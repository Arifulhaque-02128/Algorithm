#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5+5;
vector<pii> g[N];
vector<int> dist(N, INT_MAX);
bool visited[N];

void dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[0], s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;
        for(pii vp: g[u]){
            int v = vp.first;
            int w = vp.second;

            if(visited[v]) continue;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        g[u].push_back({v, w});
    }
    
    int s, d; cin>>s>>d;

    dijkstra(s);

    cout<<dist[d]<<endl;
    
    return 0;
}

// input -----> 6 9
// 1 2 5
// 2 3 2
// 1 3 10
// 3 4 1
// 4 1 5
// 1 5 9
// 5 6 1
// 2 6 4
// 2 5 2
// 4 6
