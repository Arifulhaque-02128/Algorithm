#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int m, n;
int cnt1 = 0;
int cnt2 = 0;
bool visited1[100][100];
bool visited2[100][100];
vector<pii> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pii> island2[100];

vector<vector<int>> grid1;
vector<vector<int>> grid2;

int sub_island = 0;


bool isValid(int i, int j){
    return (i>=0 && i<m && j>=0 && j<n);
}

void dfs(int i, int j, int count, int matrix){

    if(matrix == 1){
        visited1[i][j] = true;
    } else {
        visited2[i][j] = true;
        island2[count].push_back({i, j});
    }

    for(auto d:direc){
        int ni = i + d.first;
        int nj = j + d.second;

        if(matrix == 1){
            if(isValid(ni, nj) && !visited1[ni][nj] && grid1[ni][nj] == 1){
                visited1[ni][nj] = true;
                dfs(ni, nj, count, 1);
            }
        } else {
                if(isValid(ni, nj) && !visited2[ni][nj] && grid2[ni][nj] == 1){
                    visited2[ni][nj] = true;
                    dfs(ni, nj, count, 2);
            }
        }
    }
}


bool checking_subIsland(int i){
        
    bool flag = true;
        
    for(auto island: island2[i]){
        int x = island.first;
        int y = island.second;
        if(! visited1[x][y] ){
            flag = false;
            return flag;
        } 
    }
    
    return flag;
}

int main()
{

    cin>>m>>n;

    // taking input for grid 1
    for (int i = 0; i < m; i++)
    {
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            int val; cin>>val;
            vec.push_back(val);
        }
        grid1.push_back(vec);
    }

    // taking input for grid 2
    for (int i = 0; i < m; i++)
    {
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            int val; cin>>val;
            vec.push_back(val);
        }
        grid2.push_back(vec);
    }
    

    // dfs for grid 1
    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n ; j++){
            if(!visited1[i][j] && grid1[i][j] == 1){
                // cout<<i<<", "<<j<<endl;
                cnt1++;
                dfs(i, j, cnt1, 1);
            }
        }
    }
    
    

    //dfs for grid 2
    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n ; j++){
            if(!visited2[i][j] && grid2[i][j] == 1){
                cnt2++;
                dfs(i, j, cnt2, 2);
            }
        }
    }

    for(int i = 1; i<=cnt2; i++){
        bool result = checking_subIsland(i);
        if(result) sub_island++;
    }

    cout<<"Total Sub Island : "<<sub_island<<endl;
    
    return 0;
}


// input ----> 5 5
// 1 1 1 0 0
// 0 1 1 1 1
// 0 0 0 0 0
// 1 0 0 0 0
// 1 1 0 1 1
// 1 1 1 0 0
// 0 0 1 1 1
// 0 1 0 0 0
// 1 0 1 1 0
// 0 1 0 1 0

// input ----> 5 5
// 1 0 1 0 1
// 1 1 1 1 1
// 0 0 0 0 0
// 1 1 1 1 1
// 1 0 1 0 1
// 0 0 0 0 0
// 1 1 1 1 1
// 0 1 0 1 0
// 0 1 0 1 0
// 1 0 0 0 1