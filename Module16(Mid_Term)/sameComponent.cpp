#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<string> mat;
bool visited[1005][1005];
vector<pii> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m; 

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int si, int sj){
    visited[si][sj] = true;

    for(pii d:direct){
        int ni = si + d.first;
        int nj = sj + d.second;

        if(isValid(ni, nj) && !visited[ni][nj] && mat[ni][nj] != '-'){
            dfs(ni, nj);
        }
    }
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string str; cin>>str;
        mat.push_back(str);
    }

    int si, sj; cin>>si>>sj;
    int di, dj; cin>>di>>dj;

    dfs(si, sj);

    if(visited[di][dj]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}

// input ----> 5 4
// ..-.
// ---.
// ..-.
// --..
// ....
// 0 1
// 3 2


// input ----> 5 4
// ....
// ---.
// ..-.
// --..
// ....
// 0 1
// 3 2