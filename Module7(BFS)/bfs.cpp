#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
bool visited[N];

void bfs(int r){
    queue<int> q;
    q.push(r);
    visited[r] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v: adjList[u]){
            if(visited[v] == true) continue;
            else {
                q.push(v);
                visited[v] = true;
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
    
    return 0;
}


// input -----> 12
// 11
// 1 2
// 1 3
// 1 10
// 2 4 
// 2 5
// 3 9 
// 5 6
// 5 7
// 7 8
// 10 11
// 10 12