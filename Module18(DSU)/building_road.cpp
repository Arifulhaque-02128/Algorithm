//https://cses.fi/problemset/task/1666
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
long long parent[N];
long long parentLevel[N];
bool leader[N];

void dsu_set(long long n){
    for (long long i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentLevel[i] = 0;
    }
}

long long dsu_find(long long i){
    if(i == parent[i]) return i;
    else return dsu_find(parent[i]);
}

void dsu_union(long long a, long long b){
    long long LA = dsu_find(a);
    long long LB = dsu_find(b);
    if(LA != LB){
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
}

int main()
{
    long long n, m; cin>>n>>m;
    dsu_set(n);

    while (m--)
    {
        long long a, b; cin>>a>>b;
        dsu_union(a, b);
    }
    
    for (long long i = 1; i <= n; i++)
    {
        long long l = dsu_find(i);
        leader[l] = true;
    }

    vector<long long> vec;
    for (long long i = 1; i <= n; i++)
    {
        if(leader[i] == true) {
            vec.push_back(i);
        }
    }

    // required road
    cout<<vec.size() -1<<endl; 

    // road between i and i+1
    for (long long i = 0; i < vec.size() - 1; i++)
    {
        cout<<vec[i]<<" "<<vec[i+1]<<endl;
    }
    

    return 0;
}


// input ----> 4 2
// 1 2
// 3 4