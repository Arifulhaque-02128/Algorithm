#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1005;
vector<pii> adj[N];
int dist[N];
bool visited[N];
int parent[N];

void dist_init(){

    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }
}

void dijkstra(int src){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    parent[src] =  -1;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        int u = pq.top().second;

        pq.pop();

        if(visited[u]) continue;

        visited[u] = true;

        for(pii vpair: adj[u]){
            int v = vpair.first;
            int w = vpair.second;

            if(!visited[v] && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
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

    int src, dest; cin>>src>>dest;

    dist_init();

    dijkstra(src);

    vector<int> path;
    int curr = dest;

    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout<<"Shortest Path from "<<src<<" to "<<dest<<" : ";
    for(int p: path){
        cout<<p<<" ";
    }

    cout<<endl;

    cout<<"Minimum Cost "<<dist[dest]<<endl;

    return 0;
}

// input -----> 7 9
// 1 2 3
// 1 3 5
// 2 3 1
// 2 5 6 
// 3 4 1
// 3 7 12
// 4 6 1 
// 6 5 1 
// 5 7 2
// 1 7