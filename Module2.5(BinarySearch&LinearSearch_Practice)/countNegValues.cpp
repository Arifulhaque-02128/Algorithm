#include<bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        int i = 0;
        int j = 0;

        while(i<m){
            if(grid[i][j] < 0){
                cnt = cnt + (n-j);
                i++;
                j = 0;
            } else if(j == n-1){
                i++;
                j = 0;
            } else {
                j++;
            }
        }

        return cnt;
    }

int main()
{
    vector<vector<int>> v = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    int result = countNegatives(v);

    cout<<"Count : "<<result<<endl;

    return 0;
}