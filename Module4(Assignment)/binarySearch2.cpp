#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> v, int l, int r, int sz, int k){

    while (l<=r)
    {
        int mid = (l+r)/2;
        if(v[mid] == k){

            if(v[mid-1] == k) return true;

            else if(v[mid+1] == k) return true;

            else return false;

        } else if (v[mid] < k){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return false;
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

    bool result = binarySearch(v, 0, n-1, n, k);

    if(result) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}


// input ----> 7
// 1 3 4 6 6 9 17
// 6


// input ----> 10
// 0 1 2 3 4 5 6 7 8 9
// 3

