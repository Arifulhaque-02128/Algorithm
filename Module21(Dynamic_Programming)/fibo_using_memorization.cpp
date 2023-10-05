#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int memo[N];

int fibo(int n){
    if(n == 1 || n == 2){
        memo[n] = 1;
        return memo[n];
    }
    if(memo[n] != -1){
        return memo[n];
    }

    else {
        int res1 = fibo(n-1);
        int res2 = fibo(n-2);
        int res = res1 + res2;
        memo[n] = res;
        return memo[n];
    }
}

int main()
{
    int n; cin>>n;
    for (int i = 0; i < N; i++)
    {
        memo[i] = -1;
    }

    int fib = fibo(n);

    for (int i = 1; i <= n; i++)
    {
        cout<<memo[i]<<" ";
    }
    
    
    return 0;
}