#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int dp[N][N];

void memo_init(){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }
}


int totalWay(int n, int s, int w[]){

    if(n == 0){
        if(s == 0) return 1;
        else return 0;
    }

    if(dp[n][s] != -1) return dp[n][s];

    if(w[n-1] <= s){
        int choice1 = totalWay(n, s-w[n-1], w);
        int choice2 = totalWay(n-1, s, w);
        dp[n][s] = choice1 + choice2; 
        return dp[n][s];
    } else {
        return dp[n][s] = totalWay(n-1, s, w);
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

    memo_init();

    // how many way s=5 can be made
    int res = totalWay(n, s, arr); 

    cout<<res<<endl;

    
    return 0;
}

// 3
// 1 2 3
// 5