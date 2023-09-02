// cycle detection in a graph
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
int visited[N];

bool dfs(int u, int parent = -1){
    bool cycleExist = false;
    visited[u] = true;

    for(int v: adjList[u]){
        if(v == parent) continue;
        else if(visited[v]) return true;
        else cycleExist = cycleExist | dfs(v, u);
    }

    return cycleExist;
}

int main()
{
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool isCyclic = false;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        else {
            isCyclic = isCyclic | dfs(i);
        }
    }
    
    if(isCyclic) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}

// input -----> 4
// 4
// 1 2
// 2 3
// 3 4
// 4 2


// input ----> 6
// 4
// 1 2
// 2 3
// 3 4
// 5 6