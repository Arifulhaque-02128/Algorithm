#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin>>v[i]>>w[i];
    }

    int bag; cin>>bag;

    int memo[n+1][bag+1];
    int max_val = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= bag; j++)
        {
            if(i == 0 || j == 0) memo[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= bag; j++)
        {
            if(w[i-1] <= j) {
                int choice1 = memo[i-1][j-w[i-1]] + v[i-1];
                int choice2 = memo[i-1][j];
                memo[i][j] = max(choice1, choice2);
                max_val = max(max_val, memo[i][j]);
            } else {
                memo[i][j] = memo[i-1][j];
                max_val = max(max_val, memo[i][j]);
            }
        }
    }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= bag; j++)
        {
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<max_val<<endl;
    
        
    return 0;
}


// input ----> 4 
// 1 5
// 5 2
// 3 4 
// 2 3
// 7