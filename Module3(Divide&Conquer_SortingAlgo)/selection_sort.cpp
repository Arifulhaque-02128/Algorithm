#include<bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> &v, int n){
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {

        // find minimum value and it's index
        int min = v[0];
        int minIdx = 0;
        for (int j = 1; j < n; j++)
        {
            if(v[j] < min){
                min = v[j];
                minIdx = j;
            }
        }

        v.erase(v.begin()+minIdx); // remove min value from v using it's index
        vec.push_back(min); // push the min value to the new sorted array
    }

    return vec;
    
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

    vector<int> vec = selectionSort(v, n);

    for(int val:vec){
        cout<<val<<" ";
    }
    
    return 0;
}


// input ------> 10
// 70 60 10 20 50 30 80 40 90 100