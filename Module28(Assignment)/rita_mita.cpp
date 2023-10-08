// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-03/challenges/mina-and-rita
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    for (int k = 0; k < t; k++)
    {
        string str1, str2; cin>>str1>>str2;
        int n = str1.size();
        int m = str2.size();

        int dp[n+1][m+1];
        for (int i = 0; i <= m; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int res = (n+m) - dp[n][m];

        cout<<res<<endl;
    }
    
    return 0;
}

// input ----> 2
// buzzi kuzzi
// tommy batomzy