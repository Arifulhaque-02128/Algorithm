// https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-03/challenges/make-palindrome-5-2
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    for (int i = 0; i < t; i++)
    {
        string str; cin>>str;
        int n = str.size();
        string s = str;
        reverse(s.begin(), s.end());

        int dp[n+1][n+1];
        for (int i = 0; i <= n; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(str[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int res = n - dp[n][n];
        cout<<res<<endl;
    }
    
    return 0;
}


// input ----> 5
// madam
// mcadam
// madcam
// mcaedam
// macdarm