#include<bits/stdc++.h>
using namespace std;

const int N = 1004;
vector<int> adjList[N];
vector<int> dist;

void bfs(int r, int c){
    
    bool visited[N];
    int level[N];

    queue<int> q;
    q.push(r);
    visited[r] = true;
    level[r] = 0;

    if(r == c){
        dist.push_back(0);
        return;
    } else {
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int v: adjList[u]){
                if(visited[v]){
                    continue;
                }
                else {
                    q.push(v);
                    visited[v] = true;
                    level[v] = level[u] + 1;
                    if(v == c){
                        dist.push_back(level[v]);
                        return;
                    }
                }
            }
        }
        dist.push_back(-1);
        return;
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

    int k; cin>>k;
    for (int i = 0; i < k; i++)
    {
        int x, y; cin>>x>>y;
        bfs(x, y);
    }
    
    for(int val: dist){
        cout<<val<<endl;
    }
    
    return 0;
}