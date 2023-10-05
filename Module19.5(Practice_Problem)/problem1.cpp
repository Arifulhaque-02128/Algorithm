// Minimum Spanning Tree
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int parent[N];
int parentSize[N];

class Edge{
    public:
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
            return a.w < b.w;
        }
};

void dsu_set(int n){
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
    }
}

int dsu_find(int i){
    if(parent[i] == i) return i;
    else return dsu_find(parent[i]);
}

int main()
{
    int n, m; cin>>n>>m;
    dsu_set(n);

    int totalCost = 0;
    vector<Edge> g;
    while (m--)
    {
        int u, v, w; cin>>u>>v>>w;
        g.push_back(Edge(u, v, w));
    }

    sort(g.begin(), g.end(), cmp());

    for(Edge ed:g){
        int a = ed.a;
        int b = ed.b;
        int w = ed.w;

        int LA = dsu_find(a);
        int LB = dsu_find(b);

        if(LA != LB){
            totalCost += w;
            if(parentSize[LA] >= parentSize[LB]){
                parent[LB] = LA;
                parentSize[LA] += parentSize[LB];
            } else {
                parent[LA] = LB;
                parentSize[LB] += parentSize[LA];
            }
        }
    }
    
    cout<<totalCost<<endl;

    return 0;
}




// input -----> 4 4
// 1 2 1
// 2 3 2
// 3 4 5
// 4 1 4