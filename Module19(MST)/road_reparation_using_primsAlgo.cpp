// https://cses.fi/problemset/task/1675/
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pii;
const int N = 1e5+5;
vector<pii> g[N];
bool visited[N];

long long totalCost = 0;
long long cnt = 0;

class Edge{
    public:
        long long a, b, w;
    Edge(long long a, long long b, long long w){
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp{
    public:
        bool operator()(Edge a, Edge b){
            return a.w > b.w;
        }
};


void prims_algo(long long src){
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgeList;
    pq.push({src, src, 0});

    while (!pq.empty())
    {
        Edge u = pq.top();
        pq.pop();

        long long a = u.a;
        long long b = u.b;
        long long w = u.w;

        if(visited[b]) continue;

        visited[b] = true;
        cnt++;
        edgeList.push_back(u);
        totalCost += w;

        for(pii vpair:g[b]){
            long long v = vpair.first;
            long long cost = vpair.second;
            if(!visited[v]){
                pq.push(Edge(b, v, cost));
            }
        }
    }

    edgeList.erase(edgeList.begin());
}


int main()
{
    long long n, m; cin>>n>>m;
    while (m--)
    {
        long long u, v, w; cin>>u>>v>>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    prims_algo(1);

    if(cnt == n){
        cout<<totalCost<<endl;
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    return 0;
}

// input -----> 5 6
// 1 2 3
// 2 3 5
// 2 4 2
// 3 4 8
// 5 1 7
// 5 4 4