#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2; cin>>str1>>str2;
    int n = str1.size();
    int m = str2.size();

    int dp[n+1][m+1];
    for(int i = 0; i<=m; i++) dp[0][i] = 0;
    for(int i = 1; i<=n; i++) dp[i][0] = 0;

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    

    string seq;
    int ci = n;
    int cj = m;
    while(ci != 0 && cj != 0){
        if(str1[ci-1] == str2[cj-1]){
            seq = str1[ci-1] + seq;
            
            ci--;
            cj--;
        } 
        else if (dp[ci-1][cj] > dp[ci][cj-1]){
            seq = str1[ci-1] + seq;
            ci--;
        } else {
            seq = str2[cj-1] + seq;
            cj--;
        }
    }

    while(ci != 0){
        seq = str1[ci-1] + seq;
        ci--;
    }

    while(cj != 0){
        seq = str2[cj-1] + seq;
        cj--;
    }

    cout<<seq<<endl;


    return 0;
}


// input -----> abac
// cab