#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> v1, int m, vector<int> v2, int n){
    vector<int> vec;
    int i = 0;
    int j = 0;

    while(i<m && j<n){
        if(v1[i] <= v2[j]){
            vec.push_back(v1[i]);
            i++;
        } else {
            vec.push_back(v2[j]);
            j++;
        }
    }

    while (i<m && !j<n)
    {
        vec.push_back(v1[i]);
        i++;
    }

    while (j<n && !i<m)
    {
        vec.push_back(v2[j]);
        j++;
    }
    
    return vec;
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

    vector<int> vec = merge(v1, m, v2, n);

    for(int val:vec){
        cout<<val<<" ";
    }
    
    return 0;
}


// input ----> 5
// 10 20 30 40 50
// 5
// 60 70 80 90 100 

// input ----> 7
// 10 20 30 40 50 65 75
// 5
// 60 70 80 90 100 