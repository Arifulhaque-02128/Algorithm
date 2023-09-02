#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adjList[N];

int main()
{
    int n, m; cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin>>u>>v;
        adjList[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<"List for "<<i<<" : ";
        for(int v: adjList[i]){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}