#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int dp[N][N];

void init_memo(){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }
}

int unbounded_knapsack(int n, int s, int val[], int w[]){

    if(n == 0 || s == 0) return 0;

    if(dp[n][s] != -1) return dp[n][s];

    if(w[n-1] <= s){
        int choice1 = unbounded_knapsack(n, s-w[n-1], val, w) + val[n-1];
        int choice2 = unbounded_knapsack(n-1, s, val, w);
        dp[n][s] = max(choice1, choice2); // emon item nibo jaate value max hoy
        return dp[n][s];
    }
    else {
        return dp[n][s] = unbounded_knapsack(n-1, s, val, w);
    }
}

int main()
{
    int n, s; cin>>n>>s;
    int val[n];
    int w[n];
    for (int i = 0; i < n; i++) cin>>val[i];
    for (int i = 0; i < n; i++) cin>>w[i];

    init_memo();

    int res = unbounded_knapsack(n, s, val, w);

    cout<<res<<endl; // knapsack (size = 6) can be filled such a way for which value will be maximum
    cout<<dp[n][s]<<endl;
    
    return 0;
}


// input -----> 4 6
// 5 3 2 4
// 4 1 3 2