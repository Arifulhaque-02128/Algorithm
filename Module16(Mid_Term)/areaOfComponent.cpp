#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<string> mat;
bool visited[1005][1005];
vector<pii> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;
int cnt;

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int i, int j){
    visited[i][j] = true;
    cnt++;

    for(pii d:direc){
        int ni = i + d.first;
        int nj = j + d.second;
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

    int minimum = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!visited[i][j] && mat[i][j] != '-'){
                cnt=0;
                dfs(i, j);
                if(minimum == -1) minimum = cnt;
                else minimum = min(minimum, cnt);
            }
        }
    }

    
    cout<<minimum<<endl;
    
    return 0;
}


// input -----> 6 5
// ..-..
// ..-..
// -----
// .-...
// .----
// .....


// input -----> 3 3
// ---
// ---
// ---