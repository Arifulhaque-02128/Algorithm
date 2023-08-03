#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {9,6,4,2,3,5,7,0,1};
    int n = v.size();
    sort(v.begin(), v.end());

    int missingNum;
    for(int i = 0; i<=n; i++){
        if(i == n){
            missingNum = n;
        }
        else if(v[i] != i){
            missingNum = i;
            break;
        }
    }

    cout<<missingNum<<endl;
    
    return 0;
}