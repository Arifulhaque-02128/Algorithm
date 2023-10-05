// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X
#include<bits/stdc++.h>
using namespace std;

int arr[11][11];
int n, m;
const int INF = -100005;

bool isValid(int idx, int h){
    return (idx+1) < h;
}

long long max_sum(int i, int j){
    if(i == n-1 && j == m-1) return arr[i][j];
    long long down=INF;
    long long right=INF;
    if(isValid(i, n)){
        down = max_sum(i+1, j);
    } 
    if(isValid(j, m)){
        right = max_sum(i, j+1);
    }
    return arr[i][j] + max(down, right);
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }

    long long sum = max_sum(0, 0);

    cout<<sum<<endl;
    
    return 0;
}


// input ----> 3 3
// 5 2 4
// 1 3 5
// 9 2 7


