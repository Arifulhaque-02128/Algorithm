// https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03-1/challenges/chocolates-22-1/problem
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    for (int k = 0; k < t; k++)
    {
        int n; cin>>n;
        int arr[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }

        if(sum%2 != 0){
            cout<<"NO"<<endl;
        } else {
            int s = sum/2;
            bool dp[n+1][s+1];
            dp[0][0] = true;
            for(int i=1; i<=s; i++) dp[0][i] = false;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= s; j++)
                {
                    if(arr[i-1] <= j){
                        bool choice1 = dp[i-1][j-arr[i-1]];
                        bool choice2 = dp[i-1][j];
                        dp[i][j] = choice1 || choice2;
                    }
                    else dp[i][j] = dp[i-1][j];
                }
            }

            if(dp[n][s]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    
    return 0;
}


// input -----> 3
// 5
// 1 2 3 4 5
// 4
// 2 3 4 5
// 5
// 1 2 3 8 12