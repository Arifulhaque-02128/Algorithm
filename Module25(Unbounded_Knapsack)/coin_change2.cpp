#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;
const int INF_MAX = 1e8;
const int N = 1e3+5;
int dp[N][N];

void memo_init(){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = INF_MAX;
        }
    }
}

int unbounded_knapsack(int n, int s, int w[]){

    if(n == 0){
        if(s == 0) return 0;
        else return INF;
    }

    if(dp[n][s] != INF_MAX) return dp[n][s];
    
    if(w[n-1] <= s){
        int choice1 = unbounded_knapsack(n, s-w[n-1], w) + 1;
        int choice2 = unbounded_knapsack(n-1, s, w);
        dp[n][s] = min(choice1, choice2);
        return dp[n][s];
    } else {
        dp[n][s] = unbounded_knapsack(n-1, s, w);
        return dp[n][s];
    }
}

int main()
{
    int n; cin>>n;
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin>>w[i];
    }
    
    int s; cin>>s;

    memo_init();

    int res = unbounded_knapsack(n, s, w);

    cout<<res<<endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if(dp[i][j] < INF) cout<<dp[i][j]<<" ";
            else cout<<"x ";
            
        }
        cout<<endl;
    }
    

    return 0;
}



// input -----> 3
// 1 2 3
// 5

// input ----> 2
// 2 3
// 6