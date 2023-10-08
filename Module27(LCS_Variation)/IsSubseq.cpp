// Tell me if A is subsequence of B
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b; cin>>a>>b;
    int n = a.size();
    int x = 0;
    bool res = false;
    for(char ch:b){
        if(ch == a[x]){
            x++;
        }
        if(x == n){
            res = true;
            break;
        }
    }

    if(res) cout<<"YES, A is a subsequence of B"<<endl;
    else cout<<"NO, A is not a subsequence of B"<<endl;

    return 0;
}


// input -----> AXE
// BAKXZEF