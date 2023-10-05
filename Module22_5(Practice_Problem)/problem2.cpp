// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V
#include<bits/stdc++.h>
using namespace std;

int sz;
long long x;
int arr[21];

bool recursion(long long sum, int idx){
    if(sz == idx) return sum == x;
    bool r = recursion(sum+arr[idx], idx+1);
    bool l = recursion(sum-arr[idx], idx+1);

    return l || r;
}

int main()
{
    cin>>sz>>x;
    for (int i = 0; i < sz; i++)
    {
        int val; cin>>val;
        arr[i] = val;
    }
    
    bool res = recursion(arr[0], 1);

    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

// input -----> 5 5
// 1 2 3 4 5

//input ------> 5 2
// 1 2 3 4 5