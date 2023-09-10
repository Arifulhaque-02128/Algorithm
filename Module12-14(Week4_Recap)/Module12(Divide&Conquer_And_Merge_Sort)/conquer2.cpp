// 1 ta array er 2 ta sorted part ke merge kore 1 ta sorted array te convert kora laagbe.
#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left_idx, int mid_idx, int right_idx){

    // Step-1: first e left array and right array create kora lagbe
    int left_size = (mid_idx - left_idx) + 1;
    int right_size = (right_idx - mid_idx);
    int Left[left_size];
    int Right[right_size];

    // Step-2: left array te original array er 1st sorted part tuku push kora lagbe
    int k = 0;
    for (int i = left_idx; i <= mid_idx; i++)
    {
        Left[k] = arr[i];
        k++;
    }
    

    // Step-3: right array te original array er 2nd sorted part tuku push kora lagbe
    k = 0;
    for (int i = mid_idx + 1; i <= right_idx; i++)
    {
        Right[k] = arr[i];
        k++;
    }

    // Step-4: Left and Right ei 2 sorted array ke merge kore original array te rakhte hobe

    int i=0, j=0;
    int curr = left_idx;
    while ( i<left_size && j<right_size)
    {
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

    while (i<left_size)
    {
        arr[curr] = Left[i];
        i++;
        curr++;
    }
    while (j<right_size)
    {
        arr[curr] = Right[j];
        j++;
        curr++;
    }
    
}

int main()
{
    int n; cin>>n;
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin>>ar[i]; // i=0 theke i=4 porjonto ekta sorted part ar i=5 theke i=11 porjonto arekta sorted part.
    }
    
    merge(ar, 0, 4, n-1); // mid_idx = 4. karon, i=0(left_idx) theke i=4 porjonto ekta sorted part ar i=5 theke i=11(n-1, right_idx) porjonto arekta sorted part. 

    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    

    return 0;
}

// input ----> 12 
// 12 20 25 40 50 10 15 30 35 45 60 70