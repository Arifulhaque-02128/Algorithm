#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u){
    visited[u] = true;
    for(int v:adjList[u]){
        if(visited[v] == true) continue;
        else {
            depth[v] = depth[u] + 1;
            dfs(v);
            height[u] = max(height[v]+1, height[u]);
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

    cout<<"Height of the Tree : "<<height[1]<<endl;

    int maxDepth = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cout<<"Depth of "<<i<<" : "<<depth[i]<<endl;
        if(maxDepth < depth[i]){
            maxDepth = depth[i];
        }
    }
    cout<<"Depth of the Tree : "<<maxDepth<<endl;
    
    
    return 0;
}