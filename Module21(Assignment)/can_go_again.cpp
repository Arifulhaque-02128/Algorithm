// https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03/challenges/can-go-again

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
const double INF = 1e18;

typedef pair<int, long long> pii;
vector<pii> g[N];
long long dist[N];

int n, m;
bool negCycle = false;

void bellman_ford(int src){
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int i = 1; i <= n; i++)
    {
    
        for (int u = 1; u <= n; u++)
        {
            for(pii vpair:g[u]){
                int v = vpair.first;
                long long w = vpair.second;

                if(dist[u] != INF && dist[v] > (dist[u] + w)){
                    if(i == n) negCycle = true;
                    else dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    while (m--)
    {
        int u, v;
        long long w; 
        cin>>u>>v>>w;
        g[u].push_back({v, w});
    }

    int src; cin>>src;
    bellman_ford(src);

    int t; cin>>t;
    while (t--)
    {
        int val; cin>>val;
        if(!negCycle){
            if(dist[val] == INF) cout<<"Not Possible"<<endl;
            else cout<<dist[val]<<endl;
        }
    }

    if(negCycle) cout<<"Negative Cycle Detected"<<endl;
    
    
    return 0;
}


// input ----> 5 7
// 1 2 10
// 1 3 -2
// 3 2 1
// 2 4 7
// 3 4 -3
// 4 5 5
// 2 5 2
// 1
// 5
// 1
// 2
// 3
// 4
// 5


// input ----> 5 7
// 1 2 10
// 1 3 -2
// 3 2 1
// 2 4 7
// 3 4 -3
// 4 5 5
// 2 5 2
// 5
// 5
// 1
// 2
// 3
// 4
// 5


// input ---> 5 8
// 1 2 -2
// 1 3 -10
// 3 2 1
// 2 4 7
// 4 3 -3
// 4 5 5
// 2 5 2
// 4 1 1
// 1
// 5
// 1
// 2
// 3
// 4
// 5