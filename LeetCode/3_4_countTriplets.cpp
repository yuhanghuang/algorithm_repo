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

// 方法三
/*
二进制表示中，某些位置才可以是1，而其它位置不能是1
如该数是 (100111)2 ，那么满足要求的二元组可以是 (100010)2或者 (000110)2，但不能是 (010001)2 。
二进制枚举子集的步骤：

记该数为x。我们用 sub 表示当前枚举到的子集。初始时 sub=x，因为 x 也是本身的子集；
我们不断地令 sub=(sub−1) & x，其中 &表示按位与运算。这样我们就可以从大到小枚举 x 的所有子集。当 sub=0时枚举结束。

*/
class Solution2 {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(1 << 16);
        for (int x: nums) {
            for (int y: nums) {
                ++cnt[x & y];
            }
        }
        int ans = 0;
        for (int x: nums) {
            x = x ^ 0xffff;
            for (int sub = x; sub; sub = (sub - 1) & x) {
                ans += cnt[sub];
            }
            ans += cnt[0];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums={1,2,3};
    Solution sl;
    Solution2 s2;
    cout <<sl.countTriplets(nums)<<endl;
    cout <<s2.countTriplets(nums);
}