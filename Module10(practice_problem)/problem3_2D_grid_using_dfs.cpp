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

bool dfs(int i, int j){
    if(i == di && j == dj) return true;

    bool flag = false;
    visited[i][j] = true;

    if(isValid(i, j+1) && g[i][j+1] != 'x' && visited[i][j+1] == false ){
        flag = flag || dfs(i, j+1);
    }
    if(isValid(i, j-1) && g[i][j-1] != 'x' && visited[i][j-1] == false ){
        flag = flag || dfs(i, j-1);
    }
    if(isValid(i+1, j) && g[i+1][j] != 'x' && visited[i+1][j] == false ){
        flag = flag || dfs(i+1, j);
    }
    if(isValid(i-1, j) && g[i-1][j] != 'x' && visited[i-1][j] == false){
        flag = flag || dfs(i-1, j);
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
    
    bool result = dfs(si, sj);

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

// input -----> 5 5
// .....
// .....
// .x..e
// s.x..
// ....x
