// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col; cin>>row>>col;
    int arr[11][11];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
    }

    int memo[11][11];
    memo[0][0] = arr[0][0];

    // initializing the first row
    for (int i = 1; i < col; i++)
    {
        memo[0][i] = memo[0][i-1] + arr[0][i];
    }
    
    // initializing the first column
    for (int i = 1; i < row; i++)
    {
        memo[i][0] = memo[i-1][0] + arr[i][0];
    }

    // fillup other cell of the memo array
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            memo[i][j] = arr[i][j] + max(memo[i-1][j], memo[i][j-1]);
        }
    }

    cout<<memo[row-1][col-1]<<endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<memo[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    
    
    return 0;
}



// input  -----> 3 3
// 5 2 4
// 1 3 5
// 9 2 7