#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> v1, int m, vector<int> v2, int n){
    vector<int> v;
    v1.push_back(INT_MIN);
    v2.push_back(INT_MIN);

    int lp = 0, rp = 0;

    for (int i = 0; i < (n+m) ; i++)
    {
        if(v1[lp] >= v2[rp]){
            v.push_back(v1[lp]);
            lp++;
        } else {
            v.push_back(v2[rp]);
            rp++;
        }
    }
    
    return v;
}

int main()
{
    int m; cin>>m;
    vector<int> v1;
    for (int i = 0; i < m; i++)
    {
        int val; cin>>val;
        v1.push_back(val);
    }

    int n; cin>>n;
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        v2.push_back(val);
    }

    vector<int> v = merge(v1, m, v2, n);

    for(int val:v){
        cout<<val<<" ";
    }
    
    return 0;
}

// input ----> 4
// 8 6 4 2
// 4
// 7 5 3 1
