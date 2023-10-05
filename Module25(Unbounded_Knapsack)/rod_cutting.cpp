#include<bits/stdc++.h>
using namespace std;

int main()
{
    int len; cin>>len;
    int val[len]; 
    int w[len];
    for (int i = 0; i < len; i++)
    {
        cin>>val[i];
        w[i] = i+1;
    }

    // w -> includes inches and val-> includes corresponding value of that inches' wood

    // for (int i = 0; i < len; i++)
    // {
    //     cout<<w[i]<< " : "<<val[i]<<endl;
    // }

    int dp[len+1][len+1];
    for (int i = 0; i <= len; i++) dp[0][i] = 0;
    for (int i = 1; i <= len; i++) dp[i][0] = 0;

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            if(w[i-1] <= j){
                int choice1 = dp[i][j-w[i-1]] + val[i-1];
                int choice2 = dp[i-1][j];
                dp[i][j] = max(choice1, choice2);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout<<"Maximum Value : "<<dp[len][len]<<endl;
    
    return 0;
}