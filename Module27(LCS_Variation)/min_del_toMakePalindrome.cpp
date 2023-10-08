// minimum insertion or deletation to make a string Palindrome
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a; cin>>a;
    int n = a.size();

    string b = a; 
    reverse(b.begin(), b.end());

    int dp[n+1][n+1];
    for(int i=0; i<=n; i++) dp[0][i] = 0;
    for(int i=1; i<=n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } 
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int minInsert = n - dp[n][n];
    int minDel = n - dp[n][n];

    cout<<"Minimum no. of Insertion : "<<minInsert<<endl;
    cout<<"Minimum no. of Deletation : "<<minDel<<endl;
    
    return 0;
}


// input -----> agbcba