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
            if(visited[v] == true) continue;
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

    for (int i = 0; i < N; i++)
    {
        level[i] = -1;
    }
    
    bfs(0);

    int k; cin>>k;
    vector<int> shops;

    for(int i = 0; i < N; i++){
        if(level[i] == k){
            shops.push_back(i);
        }
    }

    sort(shops.begin(), shops.end());

    if(shops.size() > 0){
        for(int val: shops){
            cout<<val<<" ";
        }
    } else {
        cout<<-1<<endl;
    }
    
    return 0;
}


// input ----> 3 2
// 0 1
// 0 2
// 1
