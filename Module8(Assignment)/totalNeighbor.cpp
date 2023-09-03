#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adjList[N];
bool visited[N];
int cnt = 0;

void dfs(int u){
    visited[u] = true;
    for(int v: adjList[u]){
        if(visited[v]) continue;
        else {
            cnt++;
            dfs(v);
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
    }

    int k; cin>>k;
    dfs(k);

    cout<<cnt<<endl;

    return 0;
}


// input -----> 6 5
// 0 1
// 0 2
// 0 3
// 2 3
// 4 5
// 2


// input -----> 6 5
// 0 1
// 0 2
// 2 3
// 3 0
// 4 5
// 2