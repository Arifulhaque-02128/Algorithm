// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W
#include<bits/stdc++.h>
using namespace std;

bool reachValue(long long mul, long long n){
    if(mul == n) return true;
    if(mul > n) return false;

    bool r = reachValue(mul*10, n);
    bool l = reachValue(mul*20, n);

    return l || r;
}

int main()
{
    int t; cin>>t;
    for (int i = 0; i < t; i++)
    {
        long long n; cin>>n;

        bool res = reachValue(1, n);

        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}


// input ----> 5
// 1
// 2
// 10
// 25
// 200