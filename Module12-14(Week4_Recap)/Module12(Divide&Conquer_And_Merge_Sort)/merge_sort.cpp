#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start_idx, int mid_idx, int end_idx){

    int left_size = (mid_idx - start_idx) + 1;
    int right_size = (end_idx - mid_idx);
    int Left[left_size];
    int Right[right_size];

    for (int i = 0; i < left_size; i++)
    {
        Left[i] = arr[start_idx + i];
    }

    cout<<"Left : ";
    for (int i = 0; i < left_size; i++)
    {
        cout<<Left[i]<<" ";
    }
    

    for (int i = 0; i < right_size; i++)
    {
        Right[i] = arr[mid_idx + 1 + i];
    }

    cout<<endl;

    cout<<"Right : ";
    for (int i = 0; i < right_size; i++)
    {
        cout<<Right[i]<<" ";
    }

    cout<<endl;


    
    
    int i=0, j=0;
    int curr=start_idx;
    while (i<left_size && j<right_size)
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


void divideAndConquer(int arr[], int start, int end){

    if(start < end){

        int mid = (start + end)/2;

        divideAndConquer(arr, start, mid);
        divideAndConquer(arr, mid+1, end);

        cout<<"Part : ";
        cout<<start<<" "<<mid<<" "<<end<<endl;

        merge(arr, start, mid, end);
    }
}

int main()
{
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    divideAndConquer(arr, 0, n-1); // input ----> arr, start_idx, end_idx

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

// input ----> 12
// 5 3 20 30 40 15 25 17 50 66 70 57 