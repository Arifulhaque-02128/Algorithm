#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
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
            if(visited[v]){
                continue;
            }
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
    int n,m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    long long k; cin>>k;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            visited[j] = false;
            level[j] = -1;
        }
        
        int x, y; cin>>x>>y;
        bfs(x);

        if(visited[y]){
            cout<<level[y]<<endl;
        } else cout<<-1<<endl;
    }
    
    return 0;
}



// input -----> 6 7
// 0 1
// 0 2
// 1 2
// 0 3
// 4 2
// 3 5
// 4 3
// 6
// 0 5
// 1 5
// 2 5
// 2 3
// 1 4
// 0 0



// input -----> 7 6
// 0 1
// 0 2
// 1 2
// 0 3
// 4 2
// 4 3
// 4
// 3 10
// 2 6
// 0 6
// 0 10