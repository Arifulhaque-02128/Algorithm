#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int l, int r, int sz, int k){

    while (l<=r)
    {
        int mid = (l+r)/2;
        if(v[mid] == k){
            return mid;
        } else if (v[mid] < k){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
    int n; cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        v.push_back(val);
    }

    int k; cin>>k;

    int result = binarySearch(v, 0, n-1, n, k);

    if(result == -1) cout<<"Not Found"<<endl;
    else cout<<result<<endl;
    
    return 0;
}


// input -----> 8
// -4 0 2 6 9 10 29 54
// 29

// input ----> 10
// 0 1 2 3 4 5 6 7 8 9
// -3
