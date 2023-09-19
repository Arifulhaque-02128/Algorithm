#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int parentLevel[1000];

void dsu_set(int n){
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentLevel[i] = 0;
    }
}

int dsu_find(int i){
    if(parent[i] == i) return i;
    else return dsu_find(parent[i]);
}

void dsu_union(int LA, int LB){
    if(parentLevel[LA] > parentLevel[LB]){
        parent[LB] = LA;
    }
    else if(parentLevel[LA] < parentLevel[LB]){
        parent[LA] = LB;
    }
    else {
        parent[LB] = LA;
        parentLevel[LA]++;
    }
}

int main()
{
    int n, e; cin>>n>>e;
    dsu_set(n);

    int flag = false;
    while (e--)
    {
        int a, b; cin>>a>>b;
        int LA = dsu_find(a);
        int LB = dsu_find(b);
        if(LA == LB) {
            flag = true;
            break;
        } else {
            dsu_union(LA, LB);
        }
    }

    if(flag) cout<<"Cycle Detected"<<endl;
    else{
        for (int i = 1; i <= n; i++)
        {
            cout<<"parent of "<<i<<" = "<<parent[i]<<endl;
        }
    }

    return 0;
}


// input ----> 5 5 
// 1 2 
// 2 5
// 1 4
// 2 3
// 4 5