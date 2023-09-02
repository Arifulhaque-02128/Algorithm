#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u){
    visited[u] = true;
    cout<<u<<" ";
    for(int v: adjList[u]){

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


// input -----> 10 
// 9
// 1 2 
// 1 3
// 1 10
// 2 4
// 4 7
// 4 8
// 3 5 
// 3 6
// 6 9