#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &v, int l, int r, int mid){
    int left_size = mid-l+1;
    int L[left_size + 1];

    int right_size = r-mid;
    int R[right_size + 1];

    for (int i = l, j=0; i <= mid; i++, j++)
    {
        L[j] = v[i];
    }

    for (int i = mid+1, j=0; i <= r; i++, j++)
    {
        R[j] = v[i];
    }

    L[left_size] = INT_MIN;
    R[right_size] = INT_MIN;

    int lp = 0, rp = 0;

    for (int i = l; i <= r; i++)
    {
        if(L[lp] >= R[rp]){
            v[i] = L[lp];
            lp++;
        } else {
            v[i] = R[rp];
            rp++;
        }
    }
}

void mergeSort(vector<int> &v, int l, int r){

    if(l == r) return;

    int mid = (l+r)/2;
    mergeSort(v, l, mid); // divide ---> left segment
    mergeSort(v, mid+1, r); // divide ----> right segment
    merge(v, l, r, mid); // conquer ----> merge left and right
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

    mergeSort(v, 0, n-1);

    for(int val:v){
        cout<<val<<" ";
    }
    
    return 0;
}


// input -----> 7
// 1 2 9 4 0 2 5


// input -----> 6
// 5 3 -1 3 3 8

