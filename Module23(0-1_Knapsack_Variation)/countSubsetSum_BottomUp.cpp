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
    int dp[n+1][s+1];

    dp[0][0] = 1;

    for(int i=1; i<=s; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if(arr[i-1] <= j){
                int choice1 = dp[i-1][j-arr[i-1]];
                int choice2 = dp[i-1][j];

                dp[i][j] = choice1 + choice2;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    // printing the table
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    cout<<"RESULT : "<<dp[n][s]<<endl;
    
    return 0;
}


// input -----> 4
// 1 2 4 6
// 7