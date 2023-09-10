#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pii;
const int N = 1005;
vector<pii> adj[N];
long long dist[N];
bool visited[N];


void dist_init(){
    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }
}

void bfs(long long src){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while(!pq.empty())
    {
        long long u = pq.top().second;
        pq.pop();

        if(visited[u]) continue;

        visited[u] = true;

        for(pii vpair:adj[u]){
            long long v = vpair.first;
            long long w = vpair.second;

            if(!visited[v] && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
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
        long long u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    
    long long src; cin>>src;
    int t; cin>>t;

    dist_init();

    bfs(src);

    for (int i = 0; i < t; i++)
    {
        long long d, cost; cin>>d>>cost;
        if(dist[d] <= cost) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
 
    return 0;
}

// input -----> 5 7
// 1 2 10
// 1 3 2
// 3 2 1
// 2 4 7
// 3 4 2
// 4 5 5
// 2 5 2
// 1
// 5
// 1 0
// 2 5
// 3 1
// 4 4
// 5 6