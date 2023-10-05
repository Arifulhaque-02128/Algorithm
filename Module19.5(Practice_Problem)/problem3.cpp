#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5+5;
int parent[N];
int parentLevel[N];

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

void dsu_union(int a, int b){
    int LA = dsu_find(a);
    int LB = dsu_find(b);

    if(LA != LB){
        if(parentLevel[LA] > parentLevel[LB]){
            parent[LB] = LA;
        } else if(parentLevel[LB] > parentLevel[LA]){
            parent[LA] = LB;
        } else {
            parent[LB] = LA;
            parentLevel[LA]++;
        }
    }
}

int main()
{
    int n; cin>>n;
    int i = n-1;
    dsu_set(n);

    vector<pii> cycleEdge;
    while (i--)
    {
        int a, b; cin>>a>>b;

        int LA = dsu_find(a);
        int LB = dsu_find(b);

        if(LA == LB) {
            cycleEdge.push_back({a, b});
            continue;
        }

        else {
            dsu_union(a, b);
        }
    }

    int totalRoad = cycleEdge.size();

    cout<<totalRoad<<endl;

    for(pii ed:cycleEdge){
        cout<<ed.first<<" "<<ed.second<<" ";

        int leader = dsu_find(ed.first);
        int child;
        for (int i = 1; i <= n; i++)
        {
            int l = dsu_find(i);
            if(leader != l){
                child = l;
                dsu_union(leader, l);
                break;
            }
        }
        cout<<leader<<" "<<child<<endl;
    }

    
    return 0;
}


// input ----> 2
// 1 2


// input -----> 7
// 1 2
// 2 3
// 3 1
// 4 5
// 5 6
// 6 7

