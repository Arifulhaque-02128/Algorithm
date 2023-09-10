#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1005;
vector<pii> adj[N];
int dist[N];
bool visited[N];

void dist_init(){

    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }
}

void dijkstra(int src){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        int parent = pq.top().second;

        pq.pop();

        if(visited[parent]) continue;

        visited[parent] = true;

        for(pii childPair:adj[parent]){
            int child = childPair.first;
            int cost = childPair.second;

            if(!visited[child] && dist[child] > dist[parent] + cost){
                dist[child] = dist[parent] + cost;
                pq.push({dist[child], child});
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

    dijkstra(src);

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