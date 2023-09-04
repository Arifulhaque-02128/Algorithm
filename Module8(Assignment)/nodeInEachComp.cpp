#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adjList[N];
bool visited[N];
int cnt = 0;

int bfs(int r){
    queue<int> q;
    q.push(r);
    visited[r] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;

        for(int v: adjList[u]){
            if(visited[v] == true) continue;
            else {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    return cnt;
}

int main()
{
    int n,m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    

    vector<int> components;

    for (int i = 0; i < N; i++)
    {
        cnt = 0;
        // if(adjList[i].empty()) continue;
        if(visited[i]) continue;
        int result = bfs(i);
        if(result > 1) components.push_back(result);
    }

    sort(components.begin(), components.end());

    for(int val: components){
        cout<<val<<" ";
    }

    return 0;
}


// input -----> 9 7
// 0 1
// 1 2
// 0 2
// 2 3
// 4 5
// 5 7
// 8 9


// input -----> 5 3
// 999 1000
// 100 500
// 500 600
