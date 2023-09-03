#include<bits/stdc++.h>
using namespace std;

const long long N = 100005;
vector<long long> adjList[N];
vector<long long> dist;
bool visited[N];
long long level[N];

void bfs(long long r){

    queue<long long> q;
    q.push(r);
    visited[r] = true;
    level[r] = 0;

    while (!q.empty())
    {
        long long u = q.front();
        q.pop();

        for(long long v: adjList[u]){
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

    long long n,m; cin>>n>>m;
    for (long long i = 0; i < m; i++)
    {
        long long u, v; cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bfs(0);

    long long k; cin>>k;
    vector<long long> shops;

    for(long long i=0; i<n; i++){
        if(level[i] == k){
            shops.push_back(i);
        }
    }

    sort(shops.begin(), shops.end());

    if(shops.size() > 0){
        for(long long val: shops){
            cout<<val<<" ";
        }
    } else {
        cout<<-1<<endl;
    }
    
    return 0;
}