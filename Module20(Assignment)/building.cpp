// https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03/challenges/building-3-1

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int parent[N];
int parentLevel[N];

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
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentLevel[i] = 0;
    }
}

int dsu_find(int v){
    if(parent[v] == v) return v;
    else return dsu_find(parent[v]);
}

int main()
{
    int n, e; cin>>n>>e;

    dsu_set(n);
    vector<Edge> g;
    while (e--)
    {
        int a, b; 
        long long w;
        cin>>a>>b>>w;

        g.push_back(Edge(a, b, w));
    }

    sort(g.begin(), g.end(), cmp());

    vector<Edge> edgeList;
    long long totalCost = 0;
    for(Edge ed:g){
        int a = ed.a;
        int b = ed.b;
        int w = ed.w;

        int LA = dsu_find(a);
        int LB = dsu_find(b);

        if(LA != LB){
            edgeList.push_back(Edge(ed));
            totalCost += w;

            if(parentLevel[LA] > parentLevel[LB]){
                parent[LB] = LA;
            }
            else if(parentLevel[LB] > parentLevel[LA]){
                parent[LA] = LB;
            } else {
                parent[LB] = LA;
                parentLevel[LA]++;
            }
        }
    }

    int totalEdge = edgeList.size();
    if(totalEdge == (n-1) ) cout<<totalCost<<endl;
    else cout<<-1<<endl;
    
    return 0;
}


// input ----> 5 7
// 1 2 10
// 1 3 5
// 3 2 4
// 2 4 1
// 3 4 2
// 4 5 3
// 1 5 2


// input ----> 3 2
// 1 2 10
// 2 1 2