// bfs is used because we need to find min. no. of step (shortest path) and no weight is used.
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3+5;
vector<string> g;
bool visited[N][N];
int level[N][N]; // level = minimum no. of step

vector<pii> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m; 
int si, sj, di, dj;

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(int si, int sj){
    queue<pii> q;
    q.push({si, sj});

    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;

        q.pop();
        for(pii d:direc){
            int ni = i+d.first;
            int nj = j+d.second;
            if(isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x'){
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string s; cin>>s;
        g.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(g[i][j] == 's'){
                si = i; sj = j;
            }
            if(g[i][j] == 'e'){
                di = i; dj = j;
            }
        }
    }

    bfs(si, sj);

    if(level[di][dj]){
        cout<<level[di][dj]<<endl;
    } else {
        cout<<-1<<endl;
    }
    
    return 0;
}


// input -----> 6 5
// .s.x.
// ...x.
// ..x..
// ..x..
// ..xex
// .....

// input -----> 5 5
// .s.x.
// ...x.
// ..x..
// ..x..
// ..xex


// input ----> 5 5
// .....
// .....
// .x..e
// s.x..
// ....x
