// reverse traversal using bfs
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
int visited[N];
stack<int> st;

void bfs(int r){
    queue<int> q;
    q.push(r);
    visited[r] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        st.push(u);

        for(int v: adjList[u]){
            if(visited[v]) continue;
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
        int u,v ; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bfs(1);

    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        cout<<val<<" ";
    }
    
    return 0;
}

// input ----> 4
// 4
// 1 2
// 3 4
// 1 3
// 2 4