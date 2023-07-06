#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int number=0;
        for(int i=0;i<nums.size();i++)
        {
            auto it=find(nums.begin(),nums.end(),nums[i]+diff);
            auto is=find(nums.begin(),nums.end(),nums[i]+2*diff);
            if(it!=nums.end() && is!=nums.end())
            {
                number++;
            }
        }
        return number;
    }
};

int main()
{
    vector<int> nums={0,1,4,6,7,10};
    int diff=3;
    Solution sl;
    cout<<sl.arithmeticTriplets(nums,diff);
}