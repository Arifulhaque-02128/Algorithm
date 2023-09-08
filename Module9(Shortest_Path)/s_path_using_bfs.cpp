// limitation - we can only solve unweighted graph using bfs
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
int level[N];
bool visited[N];
int parent[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v: adjList[u]){
            if(visited[v]) continue;
            else {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
                parent[v] = u;
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

    int s, d; cin>>s>>d; // taking source and destination
    bfs(s); // finding levels of all the nodes from source

    cout<<"Shortest Distance between "<<s<<" to "<<d<<" : "<<level[d]<<endl;
    

    // finding path 
    vector<int> path;
    int curr = d;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout<<"Shortest Path : ";
    for(int p:path){
        cout<<p<<" ";
    }
    
    return 0;
}


// input -----> 7 7
// 1 2 
// 1 3 
// 2 5 
// 3 4
// 4 6 
// 5 7
// 5 6
// 1 6


// input -----> 7 8
// 1 2 
// 1 3 
// 2 5 
// 3 4
// 3 6
// 4 6 
// 5 7
// 5 6
// 1 6
