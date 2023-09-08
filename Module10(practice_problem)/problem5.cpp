#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3+5;
vector<string> g;
bool visited[N][N];
int level[N][N];
pii parent[N][N];

int n, m; 
int si, sj, di, dj;
vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


bool isValid(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int ui, int uj){
    queue<pii> q;
    q.push({ui, uj});

    visited[ui][uj] = true;
    level[ui][uj] = 0;
    parent[si][sj] = {-1, -1};

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;

        q.pop();
        for(pii d:dir){
            int ni = i+d.first;
            int nj = j+d.second;

            
            if(isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x'){
                q.push({ni, nj});

                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string s; cin>>s;
        g.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(g[i][j] == 's') {
                si = i;
                sj = j;
            }
            if(g[i][j] == 'e') {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);
    
    if(level[di][dj]) cout<<level[di][dj]<<endl;
    else cout<<-1<<endl;


    // finding path
    vector<pii> path;
    pii curr({di, dj});

    while (curr.first != -1 && curr.second != -1)
    {
        path.push_back({curr.first, curr.second});
        curr = parent[curr.first][curr.second];
    }

    reverse(path.begin(), path.end());

    char direction[path.size()-1];

    for (int i = 0; i < path.size()-1; i++)
    {
        if(path[i].first == path[i+1].first){ // (0, 0) , (0, 2), (0, 1) era same row te ase. 
            // that means dekhte hobe next node RIGHT e naki LEFT e ache?
            if(path[i].second > path[i+1].second){
                direction[i] = 'L'; // parent node er pair er second value next node theke besi hole, next parent er LEFT e ache
            } else {
                direction[i] = 'R';
            }
        } else { // (1, 0) , (1, 2), (1, 1) era same column e ase.
            // that means dekhte hobe next node UP e naki DOWN e ache?
            if(path[i].first > path[i+1].first){
                direction[i] = 'U';// parent node er pair er second value next node theke besi hole, next parent er UP e ache
            } else {
                direction[i] = 'D';
            }
        }
    }

    for (char d:direction)
    {
        cout<<d;
    }
    
    
    return 0;
}