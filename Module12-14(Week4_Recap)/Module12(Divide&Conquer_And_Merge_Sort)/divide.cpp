#include<bits/stdc++.h>
using namespace std;

void divide(int ar[], int start, int end){

    // just printing to visualize how the array is divided
    for (int i = start; i <= end; i++)
    {
        cout<<ar[i]<<" ";
    }

    cout<<endl;
    
    // (start < end) means, array te more than 1 elements ache. That's why array ti dividable
    // otherwise array te 1 ta element thakle taake divide kora jabe na.
    if(start < end){
        int mid_idx = (end+start)/2;
        divide(ar, start, mid_idx); // for left part
        divide(ar, mid_idx + 1, end); // for right part
    }
}

int main()
{
    int n; cin>>n;
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin>>ar[i];
    }

    // dividing the array into two parts, each time
    // parameter ----> array(ar), starting_index(0), ending_index(n-1)
    divide(ar, 0, n-1); 

    
    return 0;
}