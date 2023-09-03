#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
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

    int n,m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int k; cin>>k;

    bfs(k);

    vector<int> house;

    for(int i=0; i<n; i++){
        if(level[i] == 1){
            house.push_back(i);
        }
    }

    sort(house.begin(), house.end());

    cout<<house.size()<<endl;
    
    return 0;
}


// input -----> 6 5
// 0 1
// 0 2
// 0 3
// 2 3
// 4 5
// 2