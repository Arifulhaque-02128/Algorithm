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

    bool dp[n+1][sum+1];

    dp[0][0] = true;
    for(int i=1; i<=sum; i++) dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if(arr[i-1] <= j){
                bool choice1 = dp[i-1][j-arr[i-1]];
                bool choice2 = dp[i-1][j];
                dp[i][j] = choice1 || choice2;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    vector<int> vec;

    for (int j = 0; j <= sum; j++)
    {
        if(dp[n][j]) {
            vec.push_back(j);
            // cout<<j<<" ";
        }
    }

    int minDiff = INT_MAX;
    for(int val: vec){
        int s1 = val;
        int s2 = sum - s1;

        minDiff = min(minDiff, abs(s1 - s2));
    }

    cout<<endl;
    cout<<"Minimum Subset Sum Difference : "<<minDiff<<endl;
    
    
    return 0;
} 



// input ---> 4
// 1 5 4 11