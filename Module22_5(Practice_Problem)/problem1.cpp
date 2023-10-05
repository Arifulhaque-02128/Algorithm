// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int memo[N][N];

int knapsack(int v[], int w[], int n, int s){
    if(n == 0 || s == 0) return 0;

    if(w[n-1] <= s){
        int choice1 = knapsack(v, w, n-1, s-w[n-1]) + v[n-1];
        int choice2 = knapsack(v, w, n-1, s);
        memo[n][s] = max(choice1, choice2);
        return memo[n][s];
    }
    else {
        memo[n][s] = knapsack(v, w, n-1, s);
        return memo[n][s];
    }
}

int main()
{

    int n, s; cin>>n>>s;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin>>w[i]>>v[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            memo[i][j] = -1;
        }
    }
    

    int max_sum = knapsack(v, w, n, s);
    
    cout<<max_sum<<endl;
    
    return 0;
}



// input ----> 3 8
// 3 30
// 4 50
// 5 60


// input ---> 6 15
// 6 5
// 5 6
// 6 4
// 6 6
// 3 5
// 7 2
