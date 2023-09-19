#include<bits/stdc++.h>
using namespace std;

int parent[1000];

void dsu_set(int n){
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
}

int dsu_find(int i){
    if(parent[i] == i) return i;
    else return dsu_find(parent[i]);
}

void dsu_union(int a, int b){
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if(leaderA != leaderB){
        parent[leaderB] = leaderA;
    }
}

int main()
{
    int n, e; cin>>n>>e;
    dsu_set(n);
    while (e--)
    {
        int a, b; cin>>a>>b;
        dsu_union(a, b);
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<"parent of "<<i<<" = "<<parent[i]<<endl;
    }
    
    
    return 0;
}

// input -----> 7 4
// 1 2 
// 2 3
// 4 5
// 6 5