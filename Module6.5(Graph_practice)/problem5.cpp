#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
int visited[N];
int height[N];

void dfs(int u){
    visited[u] = true;
    for(int v: adjList[u]){
        if(visited[v] == true) continue;

        else {
            dfs(v);
            height[u] = max(height[u], height[v] + 1);
        }
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

    int node; cin>>node;
    cout<<"Height of "<<node<<" = "<<height[node]<<endl;
    
    return 0;
}

// input ---> 7
// 6
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 1


// input -----> 7
// 6
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 7