#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e5+5;
int dist[N][N];
int n, m; 

void dist_init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

void print_dist(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dist[i][j] == INF) cout<<"x ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}


void floyd_warshall(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
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

    print_dist();

    floyd_warshall();

    cout<<"Shortest Distance Matrix : "<<endl;
    print_dist();
    

    return 0;
}

// input ----> 5 7
// 1 2 2
// 1 3 6 
// 2 3 1 
// 2 5 3
// 3 4 4
// 5 4 9
// 4 2 6