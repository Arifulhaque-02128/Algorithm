#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int parentLevel[1000];

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

int dsu_find(int i){
    if(parent[i] == i) return i;
    else return dsu_find(parent[i]);
}

int main()
{
    int n, e; cin>>n>>e;
    vector<Edge> g;
    dsu_set(n);
    while (e--)
    {
        int u, v, w; cin>>u>>v>>w;
        g.push_back(Edge(u, v, w));
    }

    sort(g.begin(), g.end(), cmp());

    vector<Edge> edgeList;

    for(Edge e:g){
        int a = e.a;
        int b = e.b;
        int w = e.w;

        int LA = dsu_find(a);
        int LB = dsu_find(b);

        if(LA == LB) continue;
        else {
            edgeList.push_back(e);
            if(parentLevel[LA] > parentLevel[LB]){
                parent[LB] = LA;
            }
            else if(parentLevel[LA] < parentLevel[LB]){
                parent[LA] = LB;
            }
            else {
                parent[LB] = LA;
                parentLevel[LA]++;
            }
        }
    }

    for(Edge e:edgeList){
        int a = e.a;
        int b = e.b;
        int w = e.w;

        cout<<a<<" "<<b<<" "<<w<<endl;
    }
    
    return 0;
}


// input ----> 7 11
// 1 2 5
// 1 3 7
// 2 3 9
// 2 4 6
// 3 5 8
// 4 6 8
// 5 6 5
// 3 6 7
// 2 6 15
// 4 7 11
// 6 7 9