#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int w[], int n, int bag_size){
    if(n == 0 || bag_size == 0) return 0;

    if(w[n-1] <= bag_size){
        int choice1 = knapsack(val, w, n-1, bag_size-w[n-1]) + val[n-1];
        int choice2 = knapsack(val, w, n-1, bag_size);
        return max(choice1, choice2);
    } else {
        return knapsack(val, w, n-1, bag_size);
    }
}

int main()
{
    int n; cin>>n;
    int val[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin>>val[i]>>w[i];
    }

    int bag_size; cin>>bag_size;
    

    int max_val = knapsack(val, w, n, bag_size);

    cout<<max_val<<endl;
    
    return 0;
}


// input -----> 4 
// 1 5
// 5 2
// 3 4 
// 2 3
// 7