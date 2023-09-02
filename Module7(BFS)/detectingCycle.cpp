#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];
bool visited[N];

bool dfs(int u, int parent = -1){
    bool cycleExist = false;
    visited[u] = true;
    for(int v: adjList[u]){
        if(v == parent) continue;
        else if(visited[v] == true) return true;
        else cycleExist = cycleExist || dfs(v, u);
    }

    return cycleExist;
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

    int cycleCnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        else {
            bool isCycle = dfs(i);
            if(isCycle) cycleCnt++;
        }
    }
    
    if (cycleCnt > 0){
        cout<<"Cycle Detected"<<endl;
        cout<<"No of Cycle : "<<cycleCnt<<endl;
    } else {
        cout<<"Cycle is not Detected"<<endl;
    }
    
    return 0;
}

// input ---> 5
// 4
// 1 3 
// 3 2
// 2 5
// 5 4

// input ----> 5
// 5
// 1 3 
// 3 2
// 2 5
// 5 4
// 4 3

// input ----> 9
// 8
// 1 3 
// 3 2
// 2 5
// 5 4
// 4 6
// 7 8
// 7 9
// 8 9


// input ----> 9
// 9
// 1 3 
// 3 2
// 2 5
// 5 4
// 4 6
// 4 3
// 7 8
// 7 9
// 8 9