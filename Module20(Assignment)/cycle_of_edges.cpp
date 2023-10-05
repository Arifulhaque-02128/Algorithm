// https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03/challenges/cycle-of-edges
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8;
int parent[N];
int parentSize[N];

void dsu_set(int n){
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
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
    int cycleEdge = 0;

    while(e--){

        int a, b; cin>>a>>b;

        int LA = dsu_find(a);
        int LB = dsu_find(b);
        if(LA == LB){
            cycleEdge++;
            continue;
        }
        else {
            if(parentSize[LA] >= parentSize[LB]){
                parent[LB] = LA;
                parentSize[LA] += parentSize[LB];
            } else {
                parent[LA] = LB;
                parentSize[LB] += parentSize[LA];
            }
        }
    }

    cout<<cycleEdge<<endl;
    
    return 0;
}

// input -----> 5 7
// 1 2
// 2 3
// 3 4
// 4 5
// 4 1
// 2 4
// 5 3


// input ----> 3 3
// 1 2
// 2 3
// 1 3