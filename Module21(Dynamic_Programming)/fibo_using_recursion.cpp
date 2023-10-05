#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int fibo_series[N];


int fibo(int n){
    if(n == 1 || n == 2) {
        fibo_series[n] = 1;
        return fibo_series[n];
    }

    int res1 = fibo(n-1);
    int res2 = fibo(n-2);
    int res = (res1+res2);
    
    if(fibo_series[n] == -1){
        fibo_series[n] = res;
    }
    return res;
}

int main()
{
    int n; cin>>n;

    for (int i = 0; i < N; i++)
    {
        fibo_series[i] = -1;
    }

    int fib = fibo(n);

    for (int i = 1; i <= n; i++)
    {
        cout<<fibo_series[i]<<" ";
    }
    

    return 0;
}