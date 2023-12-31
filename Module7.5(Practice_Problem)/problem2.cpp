// count the level of a specific node in graph
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
bool visited[N];
int level[N];

void bfs(int r){
    queue<int> q;
    q.push(r);
    visited[r] = true;
    level[r] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v: adjList[u]){
            if(visited[v]) continue;
            else {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
            }
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

    bfs(1);

    int node; cin>>node;
    cout<<"Level of "<<node<<" = "<<level[node]<<endl;
    
    return 0;
}

// input -----> 7
// 6
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 7


// input ----> 8
// 7
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 1 7
// 4 8
// 8
