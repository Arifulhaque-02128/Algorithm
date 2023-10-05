#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }

    if(sum%2 == 0){

        int s = sum/2;
        bool dp[n+1][s+1];

        dp[0][0] = true;
        for(int i=1; i<=s; i++) dp[0][i] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if(arr[i-1] <= j){
                    int choice1 = dp[i-1][j-arr[i-1]];
                    int choice2 = dp[i-1][j];

                    dp[i][j] = choice1 || choice2;
                }

                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        if(dp[n][s] == true) cout<<"Equal Sum Partition is possible."<<endl;
        else cout<<"Equal Sum Partition is not possible."<<endl;
        

    } else {
        cout<<"Equal Sum Partition not possible."<<endl;
    }
    
    return 0;
}

// input ----> 4
// 1 4 9 5

// input ----> 4
// 1 4 9 4


// input ----> 4
// 1 4 9 16