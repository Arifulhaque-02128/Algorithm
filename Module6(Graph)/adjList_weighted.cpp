#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<pair<int, int>> adjList[N];

int main()
{
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<"List for "<<i<<" : ";
        for (auto val:adjList[i])
        {
            cout<<"("<<val.first<<", ";
            cout<<val.second<<") ";
        }
        cout<<endl;
    }
    
    return 0;
}