#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    int e; cin>>e;
    for (int i = 0; i < e; i++)
    {
        int u, v; cin>>u>>v;
        pq.push({u, v});
    }

    while (!pq.empty())
    {
        int u = pq.top().first;
        int v = pq.top().second;

        pq.pop();

        cout<<u<<" "<<v<<endl;
    }
    
    return 0;
}

// input ----> 6
// 3 4
// 3 2
// 3 5
// 1 5
// 1 4
// 1 2