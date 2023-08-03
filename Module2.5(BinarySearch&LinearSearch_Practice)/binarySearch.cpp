#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target; cin>>target;

    int l = 0;
    int r = nums.size() -1;
    int idx = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        int mid = (l+r)/2;
        if(nums[mid] == target){
            idx = mid;
            break;
        }
        else if(target < nums[mid]){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout<<idx<<endl;
    
    return 0;
}