// https://leetcode.com/problems/min-cost-climbing-stairs/ 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int memo[N];

int min_cost(vector<int> cost, int n){
    if(n == 0 || n == 1) return 0;

    if(memo[n] != -1) return memo[n];

    int choice1 = cost[n-1] + min_cost(cost, n-1);
    int choice2 = cost[n-2] + min_cost(cost, n-2);

    memo[n] = min(choice1, choice2);
    return memo[n];
}

int main()
{
    int n; cin>>n;
    vector<int> cost;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        cost.push_back(val);
    }

    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }
    

    int total_cost = min_cost(cost, n);

    cout<<total_cost<<endl;
    
    return 0;
}

// input ----> 3
// 10 15 20


// input -----> 10
// 1 100 1 1 1 100 1 1 100 1