#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            dp[i]=1;
            // res.push_
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                 dp[i]=max(dp[i],dp[j]+1);
            }
            res=max(res,dp[i]);
        }
        return res;

    }
};
int main()
{
    vector<int> nums={10,9,2,102,3,18,101,18};
    Solution sl;
    cout<<sl.lengthOfLIS(nums);
}