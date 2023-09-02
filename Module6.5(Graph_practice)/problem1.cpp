// undirected graph & print dfs traversal in reverse order
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u){
    visited[u] = true;
    for(int v: adjList[u]){
        if(visited[v] == true) continue;

        else {
            dfs(v);
        }
    }
    cout<<u<<" ";
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
    // cout<<endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<"List for "<<i<<" : ";
    //     for(int v: adjList[i]){
    //         cout<<v<<" ";
    //     }
    //     cout<<endl;
    // }
    
    
    return 0;
}


// input ----> 4
// 4 
// 1 2 
// 4 3 
// 3 2
// 2 4