#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {-2,-1,-1,1,2,3};

    int negCnt = 0;
    int posCnt = 0;
    
    for(int val:v){
        if(val < 0){
            negCnt++;
        }
        else if (val > 0){
            posCnt++;
        }
    }

    int maxCnt = max(negCnt, posCnt);
    cout<<maxCnt<<endl;
    
    return 0;
}