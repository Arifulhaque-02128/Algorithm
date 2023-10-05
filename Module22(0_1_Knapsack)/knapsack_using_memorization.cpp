#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+3;
int memo[N][N];

void memo_init(int n, int bag){
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= bag; j++)
        {
            memo[i][j] = -1;
        }
    }
}

int knapsack(int v[], int w[], int n, int bag){
    if(n == 0 || bag == 0) return 0;

    if(memo[n][bag] != -1) return memo[n][bag];

    if(w[n-1] <= bag){
        int choice1 = knapsack(v, w, n-1, bag-w[n-1]) + v[n-1];
        int choice2 = knapsack(v, w, n-1, bag);
        memo[n][bag] = max(choice1, choice2);
        return memo[n][bag];
    } else {
        memo[n][bag] = knapsack(v, w, n-1, bag);
        return memo[n][bag];
    }
}

int main()
{
    int n; cin>>n;
    int val[n], w[n];

    for (int i = 0; i < n; i++)
    {
        cin>>val[i]>>w[i];
    }
    
    int bag; cin>>bag;

    memo_init(n, bag);

    int max_val = knapsack(val, w, n, bag);

    cout<<max_val<<endl;

    return 0;
}


// input ----> 4 
// 1 5
// 5 2
// 3 4 
// 2 3
// 9