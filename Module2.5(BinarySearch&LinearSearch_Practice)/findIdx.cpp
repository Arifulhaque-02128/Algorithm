#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1,2,5,2,3};
    int target; cin>>target;

    // sorting 
    sort(v.begin(), v.end());

    vector<int> idx;
    for(int i = 0; i<v.size(); i++){
        if(v[i] == target) idx.push_back(i);
    }

    for(int val: idx){
        cout<<val<<" ";
    }

    return 0;
}