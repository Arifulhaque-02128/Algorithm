#include<bits/stdc++.h>
using namespace std;

bool dp[1005][1005];

bool subsetSum(int n, int arr[], int s){
    if(n == 0) {
        if(s == 0){
            return true;
        } else {
            return false;
        }
    }

    if(dp[n][s] == true) return dp[n][s];

    if(arr[n-1] <= s) {
        bool choice1 = subsetSum(n-1, arr, s-arr[n-1]);
        bool choice2 = subsetSum(n-1, arr, s);

        dp[n][s] = choice1 || choice2;
        return dp[n][s];
    } 

    else {
        dp[n][s] = subsetSum(n-1, arr, s);
        return dp[n][s];
    }
}


int main()
{
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int s; cin>>s;

    bool res = subsetSum(n, arr, s);

    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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