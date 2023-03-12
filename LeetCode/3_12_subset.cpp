/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//如果用位来表示是否选中来表示子集，那么n位的子集数目为1<<n，比如3位一共就有8种情况000 - 111，某位置选中就是1，比如101中第1，3位为1则表示选中了1，3元素，第二个元素不取\
因此，101就是一个子集，但是我们现在需要知道对于子集101我们选中了那些元素，可以知道选中了1.3号元素，那么如何可以求呢，我们自己只需要遍历每一个位置。看是否为1即可，此处可以或运算& \
要知道某个位置是否选中，首先1<<该位置，得到的数子就只有该位置为1其余位置为0.而或运算的特点是都为1才为1，只有有一个是0，那么结果就是0，因此将101 & 1<<i就可以知道i位置是否被选中，i选中的话，那么101\
这个的子集就包括该i号元素。
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> ans;
        for(int i=0;i<(1<<nums.size());i++)   
        {
            tmp.clear();
            for(int t=0;t<nums.size();t++)
            {
                if(i & (1<<t))
                {
                    tmp.push_back(nums[t]);
                }
            }
            ans.push_back(tmp);

        }
        return ans;

    }
};
int main()
{
    Solution sl;
    vector<int> nums={1,2,3};
    sl.subsets(nums);
}