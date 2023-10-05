// https://leetcode.com/problems/house-robber/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int memo[N];


int max_amount(vector<int> cost, int n){
    if(n < 0) return 0;
    if(n == 0) return cost[n];

    if(memo[n] != -1) return memo[n];

    int choice1 = cost[n] + max_amount(cost, n-2);
    int choice2 = cost[n-1] + max_amount(cost, n-3);

    memo[n] = max(choice1, choice2);

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

    int total_money = max_amount(cost, n-1);
    
    cout<<total_money<<endl;

    return 0;
}


// input -----> 4
// 1 2 3 1

// input ----> 5
// 2 7 9 3 1