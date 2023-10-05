// https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03-1/challenges/chocolates-22-1
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int mem[N];

bool makeIt(int s, int d){

    if(s == d) return true;
    if(s > d) return false;

    if(mem[s] != -1) {
        if(mem[s] == 0) return false;
        else return true;
    }

    bool choice1 = makeIt(s+3, d);
    bool choice2 = makeIt(s*2, d);

    if(choice1 || choice2){
        mem[s] = 1;
        return true;
    }
    else {
        mem[s] = 0;
        return false;
    }
}

int main()
{
    int n; cin>>n;

    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;

        for(int i=0; i< N; i++) mem[i] = -1;

        bool res = makeIt(1, val);
        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}


// input ----> 5
// 1
// 3
// 5
// 15
// 16