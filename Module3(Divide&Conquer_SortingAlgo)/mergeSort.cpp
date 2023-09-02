#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &vec, int l, int r, int mid){
    int left_size = mid-l+1;
    int L[left_size+1];

    int right_size = r-mid;
    int R[right_size+1];

    for(int i=l, j=0; i<=mid; i++, j++){
        L[j] = vec[i];
    }

    for(int i=mid+1, j=0; i<=r; i++, j++){
        R[j] = vec[i];
    }

    L[left_size] = INT_MIN;
    R[right_size] = INT_MIN;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if(L[lp] >= R[rp]){
            vec[i] = L[lp];
            lp++;
        } else {
            vec[i] = R[rp];
            rp++;
        }
    }
}

void mergeSort(vector<int> &v, int l, int r){
    if (l == r) return;
    int mid = (l+r)/2;
    mergeSort(v, l, mid);
    mergeSort(v, mid+1, r);
    merge(v, l, r, mid);
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

    cout<<endl;

    for(int i=1; i<n; i++){
        if(v[i] < v[i-1]){
            cout<<v[i];
            break;
        }
    }

    
    return 0;
}

// input ----> 10
// 70 60 10 20 50 30 80 40 90 100