// https://cses.fi/problemset/task/1676
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
long long parent[N];
long long parentSize[N];

void dsu_set(long long n){
    for (long long i = 0; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
    }
}

long long dsu_find(long long i){
    if(parent[i] == i) return i;
    else return dsu_find(parent[i]);
}

int main()
{
    long long n, m; cin>>n>>m;
    dsu_set(n);

    long long mx = 1;
    long long cmp = n;
    while (m--)
    {
        long long a,b; cin>>a>>b;
        long long LA = dsu_find(a);
        long long LB = dsu_find(b);
        if(LA != LB) {
            cmp--;
            if(parentSize[LA] >= parentSize[LB]){
                parent[LB] = LA;
                parentSize[LA] += parentSize[LB];
                mx = max(mx, parentSize[LA]);
            }
            else if(parentSize[LA] < parentSize[LB]){
                parent[LA] = LB;
                parentSize[LB] += parentSize[LA];
                mx = max(mx, parentSize[LB]);
            }
        }
        cout<<cmp<<" "<<mx<<endl;
    }
    
    return 0;
} 

// input -----> 5 3
// 1 2
// 1 3
// 4 5