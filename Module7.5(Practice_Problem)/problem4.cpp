// count the no. of connected componet in a graph
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
int visited[N];

void bfs(int r){
    queue<int> q;
    q.push(r);
    visited[r] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v: adjList[u]){
            if(visited[v]) continue;
            else{
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

    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        bfs(i);
        cc++;
    }

    cout<<cc<<endl;

    return 0;
}


// input ----> 6
// 4
// 1 2
// 2 3
// 3 4
// 5 6


// input ----> 7
// 4
// 1 2
// 2 3
// 3 4
// 5 6