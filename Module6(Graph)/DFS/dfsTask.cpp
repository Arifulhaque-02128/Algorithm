#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u){
    visited[u] = true;
    cout<<u<<" ";
    for (int v: adjList[u])
    {
        if(visited[v] == true) continue;

        else dfs(v);
    }
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

    dfs(1);
    
    return 0;
}

// input ----> 9
// 10
// 1 2 
// 2 3 
// 3 8
// 8 7 
// 8 9
// 7 4
// 7 6
// 4 5
// 5 6
// 1 5