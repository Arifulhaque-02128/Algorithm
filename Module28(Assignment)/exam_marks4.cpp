// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-03/challenges/exam-marks-iv

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main()
{
    int t; cin>>t;
    for (int k = 0; k < t; k++)
    {
        int n, marks; cin>>n>>marks;
        int m = 1000 - marks;
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin>>ar[i];
        }

        int dp[n+1][m+1];
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) dp[0][i] = 0;
    
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if(ar[i-1] <= j){
                    int choice1 = dp[i][j-ar[i-1]];
                    int choice2 = dp[i-1][j];
                    dp[i][j] = choice1 + choice2;
                    dp[i][j] %= INF;
                } else {
                    dp[i][j] = dp[i-1][j];
                    dp[i][j] %= INF;
                }
            }
        }
        
        if(dp[n][m] > INF){
            double res = (dp[n][m] % INF);
            cout<<res<<endl;
        } else {
            cout<<dp[n][m]<<endl;
        }
        
    }
    
    return 0;
}


// input ----> 5
// 5 1000
// 1 2 3 4 5
// 5 999
// 2 3 4 5 6
// 2 900
// 30 40
// 3 904
// 2 6 5
// 2 904
// 2 5