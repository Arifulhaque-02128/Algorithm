// https://cses.fi/problemset/task/1675/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
long long parent[N];
long long parentLevel[N];

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
            return a.w < b.w;
        }
};

void dsu_set(long long n){
    for (long long i = 0; i <= n; i++)
    {
        parent[i] = i;
        parentLevel[i] = 0;
    }
}

long long dsu_find(long long i){
    if(parent[i] == i) return i;
    else return dsu_find(parent[i]);
}


int main()
{
    long long n, m; cin>>n>>m;

    long long totalCost = 0;

    dsu_set(n);

    vector<Edge> g;

    while (m--)
    {
        long long u, v, w; cin>>u>>v>>w;
        g.push_back(Edge(u, v, w));
    }
    
    sort(g.begin(), g.end(), cmp());

    vector<Edge> edgeList;

    for(Edge e:g){
        long long a = e.a;
        long long b = e.b;
        
        long long LA = dsu_find(a);
        long long LB = dsu_find(b);

        if(LA == LB) continue;
        else{
            edgeList.push_back(e);
            totalCost += e.w;
            if(parentLevel[LA] > parentLevel[LB]){
                parent[LB] = LA;
            }
            else if (parentLevel[LA] < parentLevel[LB]) {
                parent[LA] = LB;
            }
            else {
                parent[LB] = LA;
                parentLevel[LA]++;
            }
        }
    }

    // In Tree, total edge = (total node - 1)
    if(edgeList.size() == (n-1)){
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