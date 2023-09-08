#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3+5;
vector<string> g;
bool visited[N][N];

int n, m; 
int si, sj, di, dj;

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

bool bfs(int i, int j){
    queue<pii> q;
    q.push({i, j});
    bool flag = false;

    while (!q.empty())
    {
        pii u = q.front();
        int ni = u.first;
        int nj = u.second;

        q.pop();
        visited[ni][nj] = true;

        if(ni == di && nj == dj) {
            flag = true; 
            break;
        }

        if(isValid(ni, nj+1) && g[ni][nj+1] != 'x' && visited[ni][nj+1] == false ){
            q.push({ni, nj+1});
        }
        if(isValid(ni, nj-1) && g[ni][nj-1] != 'x' && visited[ni][nj-1] == false ){
            q.push({ni, nj-1});
        }
        if(isValid(ni+1, nj) && g[ni+1][nj] != 'x' && visited[ni+1][nj] == false ){
            q.push({ni+1, nj});
        }
        if(isValid(ni-1, nj) && g[ni-1][nj] != 'x' && visited[ni-1][nj] == false){
            q.push({ni-1, nj});
        }
    }
    
    return flag;
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
    
    bool result = bfs(si, sj);

    if(result) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
    return 0;
}


// input ----> 6 5
// .s.x.
// ...x.
// ..x..
// ..x..
// ..xex
// ...x.


// input -----> 6 5
// .s.x.
// ...x.
// ..x..
// ..x..
// ..xex
// .....

//input -----> 5 5
// .....
// .....
// .x..e
// s.x..
// ....x