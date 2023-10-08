// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-03/challenges/exam-marks-iii

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+9;

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
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) dp[0][i] = INF;
    
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if(ar[i-1] <= j){
                    int choice1 = dp[i][j-ar[i-1]] + 1;
                    int choice2 = dp[i-1][j];
                    dp[i][j] = min(choice1, choice2);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][m] < INF){
            cout<<dp[n][m]<<endl;
        } else {
            cout<<-1<<endl;
        }
        
    }
    
    return 0;
}


// input ----> 3
// 5 1000
// 1 2 3 4 5
// 5 999
// 2 3 4 5 6
// 2 900
// 30 40