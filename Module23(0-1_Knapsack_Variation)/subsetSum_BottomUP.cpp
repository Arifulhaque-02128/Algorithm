#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int s; cin>>s;
    bool dp[n+1][s+1];

    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if(arr[i-1] <= j){
                bool choice1 = dp[i-1][j-arr[i-1]];
                bool choice2 = dp[i-1][j];

                dp[i][j] = choice1 || choice2;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         if(dp[i][j]) cout<<"T"<<" ";
    //         else cout<<"F"<<" ";
    //     }
    //     cout<<endl;
    // }

    if(dp[n][s]) cout<<"YES"<<endl;

    return 0;
}


// input ----> 4
// 1 2 4 6
// 7


// input ----> 4
// 1 2 4 6
// 5


// input ----> 4
// 1 2 4 6
// 15