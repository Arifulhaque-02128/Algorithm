#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int n, int ar[], int s){
    if(n == 0){
        if(s == 0) return true;
        else return false;
    }

    if(ar[n-1] <= s){
        bool choice1 = subsetSum(n-1, ar, s-ar[n-1]);
        bool choice2 = subsetSum(n-1, ar, s);
        
        return choice1 || choice2;
    } else {
        return subsetSum(n-1, ar, s);
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

    int s; cin>>s;

    bool res = subsetSum(n, ar, s);

    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}


// input ----> 4
// 1 2 4 6
// 7


// input ----> 4
// 1 2 4 6
// 5


// input ----> 4
// 1 2 4 6
// 15