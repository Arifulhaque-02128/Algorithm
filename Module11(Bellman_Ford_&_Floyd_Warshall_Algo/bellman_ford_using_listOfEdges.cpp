#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3+5;
const int INF = 1e9+7;
vector<pair<pii, int>> list_of_edges;
int dist[N];

int n, m; 
int src;


void dist_initialization(){

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
}


void print_matrix(){

    cout<<"Distance from "<<src<<" - "<<endl;

    for (int i = 1; i <= n; i++)
    {
        cout<<i<<" : "<<dist[i]<<endl;
    }
}

void bellman_ford(int s){
    dist[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for(auto edge: list_of_edges){
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;

            if(dist[u] != INF && (dist[v] > dist[u] + w)){
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    dist_initialization();

    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        list_of_edges.push_back({{u, v}, w});
    }
    
    cin>>src;

    bellman_ford(src);

    print_matrix();
    
    return 0;
}

// input ------> 7 
// 10
// 1 2 6
// 1 3 5
// 1 4 5
// 2 5 -1
// 3 2 -2
// 3 5 1
// 4 3 -2
// 4 6 -1
// 5 7 3
// 6 7 3
// 1