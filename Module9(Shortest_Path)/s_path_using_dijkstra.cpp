#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 1e3+5;
vector<pii> adjList[N];
vector<int> dist(N, INT_MAX);
bool visited[N];
int parent[N];

void dijkstra(int s){
    priority_queue<int, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    parent[s] = -1;

    while (! pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for(pii vp: adjList[u]){
            int v = vp.first;
            int w = vp.second;

            if(visited[v]) continue;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
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
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int s, d; cin>>s>>d;
    dijkstra(s);

    cout<<"Shortest Distance from "<<s<<" to "<<d<<" : "<<dist[d]<<endl;

    // finding shortest path -
    int curr = d; 
    vector<int> path;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout<<"Shortest Path : ";
    for (int p: path)
    {
        cout<<p<<" ";
    }
    
    return 0;
}


// input ----> 7 8
// 1 2 3
// 1 3 5
// 2 5 6
// 3 4 1
// 4 6 1
// 6 5 1
// 5 7 2
// 3 7 12
// 1 7