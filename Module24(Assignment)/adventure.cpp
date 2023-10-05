// https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03-1/challenges/adventure-1
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n, s; cin>>n>>s;
        vector<int> w;
        vector<int> v;

        for (int j = 0; j < n; j++)
        {
            int val; cin>>val;
            w.push_back(val);
        }

        for (int j = 0; j < n; j++)
        {
            int val; cin>>val;
            v.push_back(val);
        }

        int totalVal[n+1][s+1];
        for (int j = 0; j <= n; j++)
        {
            totalVal[j][0] = 0;
        }
        for (int j = 1; j <= s; j++)
        {
            totalVal[0][j] = 0;
        }
        
        // knapsack algo
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= s; k++)
            {
                if(w[j-1] <= k){
                    int choice1 = totalVal[j-1][k-w[j-1]] + v[j-1];
                    int choice2 = totalVal[j-1][k];
                    totalVal[j][k] = max(choice1, choice2);
                }
                else {
                    totalVal[j][k] = totalVal[j-1][k];
                }
            }
        }
        
        cout<<totalVal[n][s]<<endl;
        
    }
    
    return 0;
}

// input ----->  2
// 4 7
// 2 3 4 5
// 4 7 6 5
// 4 17
// 10 1 6 9
// 6 10 10 8