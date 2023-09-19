#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5+5;
vector<pii> g[N];
bool visited[N];

class Edge {
    public : 
        int a, b, w;
    Edge(int a, int b, int w){
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

void prims_algo(int src){
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(src, src, 0));
    while (!pq.empty())
    {
        Edge u = pq.top();
        pq.pop();

        int a = u.a;
        int b = u.b;
        int w = u.w;

        if(visited[b]) continue;

        visited[b] = true;
        edgeList.push_back(u);

        for(pii vpair:g[b]){
            int v = vpair.first;
            int cost = vpair.second;
            if(!visited[v]){
                pq.push(Edge(b, v, cost));
            }
        }
    }

    // delete first (src, src, 0)
    edgeList.erase(edgeList.begin());

    for(Edge e:edgeList){
        int a = e.a;
        int b = e.b;
        int w = e.w;

        cout<<a<<" "<<b<<" "<<w<<endl;
    }
}

int main()
{
    int n, e; cin>>n>>e;

    while (e--)
    {
        int u, v, w; cin>>u>>v>>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    prims_algo(1);
    
    return 0;
}


// input -----> 8 11
// 1 2 4
// 1 5 2
// 1 4 10
// 2 4 8
// 5 4 5
// 2 3 18
// 4 3 11
// 4 7 11
// 4 8 9
// 7 6 1
// 8 6 2