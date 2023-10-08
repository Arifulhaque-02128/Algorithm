#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s;
    int n = s.size();
    string str = s;
    reverse(str.begin(), str.end());

    int dp[n+1][n+1];
    for(int i = 0; i<=n; i++) dp[0][i] = 0;
    for(int i = 1; i<=n; i++) dp[i][0] = 0;

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++){
            if(s[i-1] == str[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int lcs = dp[n][n];

    int insertion = n - lcs;
    cout<<insertion<<endl;


    return 0;
}

// input ----> mbadm

// input ----> leetcode