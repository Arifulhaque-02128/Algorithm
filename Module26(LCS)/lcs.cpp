#include<bits/stdc++.h>
using namespace std;

int LCS(string a, int n, string b, int m){

    if(n == 0 || m == 0){
        return 0;
    }
    
    if(a[n-1] == b[m-1]){
        int ans = LCS(a, n-1, b, n-1);
        return ans + 1;
    }
    else {
        int ans1 = LCS(a, n, b, m-1);
        int ans2 = LCS(a, n-1, b, m);
        return max(ans1, ans2);
    }
}

int main()
{
    string a, b; 
    cin>>a>>b;
    int n = a.size();
    int m = b.size();

    int lcs = LCS(a, n, b, m);

    cout<<lcs<<endl;

    return 0;
}


// input -----> abdfg
// bedgi