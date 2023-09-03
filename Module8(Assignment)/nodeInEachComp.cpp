#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adjList[N];
bool visited[N];
int comp[N];

void bfs(int r, int cc){
    queue<int> q;
    q.push(r);
    visited[r] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        comp[cc]++;

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
    int n,m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    

    int cc = 0;

    for (int i = 0; i < n; i++)
    {
        if(adjList[i].size() <= 0) continue;
        else if(visited[i]) continue;
        else {
            cc++;
            bfs(i, cc);
        }
    }

    vector<int> components;

    for (int i = 1; i <= cc; i++)
    {
        components.push_back(comp[i]);
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
