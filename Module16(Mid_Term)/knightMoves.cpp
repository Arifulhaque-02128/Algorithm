#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pii;
const int INF = 1e9+8;
vector<pii> direc = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

long long n, m;

long long dist[1005][1005];

bool isValid(long long i, long long j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void dist_init(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = INF;
        }
    }
}

void bfs(long long ki, long long kj){
    queue<pii> q;
    dist[ki][kj] = 0;
    q.push({ki, kj});

    while (!q.empty())
    {
        long long i = q.front().first;
        long long j = q.front().second;
        q.pop();

        for(pii d:direc){
            long long ni = i + d.first;
            long long nj = j + d.second;

            if(isValid(ni, nj) && dist[ni][nj] > (dist[i][j] + 1)){
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
}

int main()
{
    int t; cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>n>>m;
        long long ki, kj; cin>>ki>>kj;
        long long qi, qj; cin>>qi>>qj;

        dist_init();

        bfs(ki, kj);

        if(dist[qi][qj] != INF) cout<<dist[qi][qj]<<endl;
        else cout<<-1<<endl;
    }
    
    return 0;
}

// input ----> 4
// 8 8
// 0 0
// 7 7
// 5 6
// 0 1
// 0 1
// 4 4
// 0 0
// 0 1
// 2 2
// 0 0
// 0 1