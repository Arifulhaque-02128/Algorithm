#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9+9;
int dist[N][N];

int n, m;
bool cycleExist = false;

void dist_init(){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

void floyd_warshall(){
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i == j && dist[i][k] + dist[k][j] < dist[i][j]) {
                    cycleExist = true;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    return;
                }
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void print_dist(){
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++){
            if(dist[i][j] == INF) cout<<"x ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    cin>>n>>m;

    dist_init();

    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin>>u>>v>>w;
        dist[u][v] = w;
    }

    print_dist(); // cycle thakle source to source cost floyd warshall korar por kome jaabe
    
    floyd_warshall();

    cout<<"Shortest Distance using Floyd Warshall - "<<endl;
    print_dist();

    if(cycleExist) cout<<"Cycle Exist."<<endl;
    else cout<<"No Cycle Exist."<<endl;
    
    return 0;
}

// input ----> 4 5 
// 1 2 4
// 1 3 5
// 2 3 2
// 3 4 3
// 4 2 -10


// input -----> 4 4
// 1 2 4
// 1 3 5
// 3 4 3
// 4 2 -10