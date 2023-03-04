#include <string>  
#include <iostream>  
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int ans=0;
        vector<int> number(1<<16);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {

                number[nums[i]&nums[j]]++;
            }
        }
        for(auto k:nums)
        {
            for(int t=0;t<(1<<16);t++)
            // for(int t=0;t<(1<<16);t++) 不可改为for(int t=0;t<(1<<nums.size());t++)
            // 因为0 <= nums[i] < 2^16所以nums[i]&nums[j]也不会超过2^16
            {
                if((k&t)==0)
                {
                    ans+=number[t];
                }
            }

        }
        return ans;
    }
    
};
// class Solution {
// public:
//     int countTriplets(vector<int>& nums) {
//         vector<int> cnt(1 << 16);
//         for (int x: nums) {
//             for (int y: nums) {
//                 ++cnt[x & y];
//             }
//         }
//         int ans = 0;
//         for (int x: nums) {
//             for (int mask = 0; mask < (1 << 16); ++mask) {
//                 if ((x & mask) == 0) {
//                     ans += cnt[mask];
//                 }
//             }
//         }
//         return ans;
//     }
// };


int main()
{
    vector<int> nums={1,2,3};
    Solution sl;
    cout <<sl.countTriplets(nums);
}