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

    int comp = 0;

    for (int i = 1; i <= n; i++)
    {
        if(visited[i] == true) continue;
        else {
            bfs(i);
            comp++;
        }
    }
    
    cout<<"Total no. of Connected Component : "<<comp<<endl;
    
    return 0;
}


// input ---> 7
// 6
// 1 2
// 1 3
// 2 3
// 2 4
// 5 6
// 7 0