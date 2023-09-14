#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int main()
{
    int n; cin>>n;
    int dist[n+1][n+1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val; cin>>val;
            dist[i][j] = val;
        }
    }

    // floyd algo

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // print the dist matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}



// input -----> 4
// 0 5 9 100
// 100 0 2 8
// 100 100 0 7
// 4 100 100 0