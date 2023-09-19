#include<bits/stdc++.h>
using namespace std;

int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};

int dsu_find(int i){
    if(parent[i] == -1) return i;
    else return dsu_find(parent[i]);
}

int main()
{
    // n ----> any value between 0 to 7
    int n; cin>>n;

    int res = dsu_find(n);

    cout<<"LEADER : "<<res<<endl;
    
    return 0;
}