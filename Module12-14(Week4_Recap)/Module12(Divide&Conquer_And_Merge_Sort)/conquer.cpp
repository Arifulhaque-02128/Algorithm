#include<bits/stdc++.h>
using namespace std;


void conquer(int Left[], int Right[], int arr[], int left_size, int right_size, int new_size){
    int i = 0; // pointer of left array
    int j = 0; // pointer of right array
    int curr = 0; // pointer of new array

    // left and right array te jodi element thake -
    // then, left ar right array er duita element er majhe compare kora hobe ke choto
    // je choto taake new array te push kora hobe. corresponding array er pointer and new array pointer 1 bariye deya hobe
    while(i<left_size && j<right_size){
        if(Left[i] <= Right[j]){
            arr[curr] = Left[i];
            i++;
            curr++;
        } else {
            arr[curr] = Right[j];
            j++;
            curr++;
        }
    }

    // right array khali kintu left array te jodi element theke jay
    while (i<(left_size))
    {
        arr[curr] = Left[i];
        i++;
        curr++;
    }
    // left array khali kintu right array te jodi element thkeke jay
    while (j<(right_size))
    {
        arr[curr] = Right[j];
        j++;
        curr++;
    }
    
}

int main()
{
    int m, n; cin>>m>>n;
    int arr1[m], arr2[n];

    for (int i = 0; i < m; i++)
    {
        cin>>arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin>>arr2[i];
    }

    // conquere means merging.
    int sorted_arr[m+n];
    conquer(arr1, arr2, sorted_arr, m, n, m+n); // merging two sorted array into 1 sorted array.

    for (int i = 0; i < (m+n); i++)
    {
        cout<<sorted_arr[i]<<" ";
    }
    

    return 0;
}


// input ----> 5 7
// 5 10 20 30 40 
// 15 25 35 50 60 70 75 