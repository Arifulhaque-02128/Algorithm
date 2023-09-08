#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int g[N][N];
bool visited[N][N];

vector<pair<int, int>> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;

bool isValid(int i, int j){
    return (i>=0 && i<m && j>=0 && j<n);
}


void dfs(int i, int j){

    visited[i][j] = true;
    for(auto d: direc){
        int ni = i + d.first;
        int nj = j + d.second;

        if(isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 0){
            dfs(ni, nj);
        }
    }
}

int main()
{
    cin>>m>>n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value; cin>>value;
            g[i][j] = value;
        }
    }
    
    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!visited[i][j] && g[i][j] != 0){
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
    
    
    return 0;
}



// input ----> 4 5
// 1 1 1 1 0
// 1 1 0 1 0
// 1 1 0 0 0
// 0 0 0 0 0

// input -----> 4 5
// 1 1 0 0 0
// 1 1 0 0 0
// 0 0 1 0 0 
// 0 0 0 1 1