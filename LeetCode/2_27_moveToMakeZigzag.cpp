#include <string>  
#include <iostream>  
#include <vector>
#include<algorithm>
using namespace std;
/*
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int count1=0;
        int count2=0;
        // if(nums[0]>nums[1])
        if(1)
        {
            for(int j=1;(2*j-1)<nums.size()-1;j++)
            {
                int k=2*j-1;
                if(nums[k]<nums[k-1] && nums[k]<nums[k+1])
                {
                    continue;
                }
                else
                {
                    count1+=max(nums[k]-nums[k+1]+1,nums[k]-nums[k-1]+1);

                    
                }
            }
        }
        // else if(nums[0]<nums[1])
        if(1)
        {
            for(int j=1;(2*j-1)<nums.size()-1;j++)
            {
                int k=2*j-1;
                if(nums[k]>nums[k-1] && nums[k]>nums[k+1])
                {
                    continue;
                }
                else
                {
                    count2+=max(nums[k-1]-nums[k]+1,nums[k+1]-nums[k]+1);
                    if(nums[k-1]-nums[k]>0)
                    {
                        nums[k-1]=nums[k]-1;
                    }
                    else
                    {
                        nums[k+1]=nums[k]-1;
                    }
                }
            }
        }
        // if(count1!=0)
        //     return count1;a
        // else
        //  {
        //      return count2;
        //  }
        return min(count1,count2);

    }
};*/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int ans1=0, ans2=0;
        for (int i=0; i<n; ++i) {
            //把该位置变成比前一个小需要d1步
            int d1 = (i>0 && nums[i]>=nums[i-1]) ? (nums[i] - nums[i-1] + 1) : 0;
            //把该位置变成比后一个小需要d2步
            int d2 = (i<n-1 && nums[i]>=nums[i+1]) ? (nums[i] - nums[i+1] + 1) : 0;
            //取max就把该位置凹下去
            //按奇偶累加
            if (i%2) {
                ans1 += max(d1, d2);
            } else {
                ans2 += max(d1, d2);
            }
        }
        //按奇偶位置凹下去需要比较少的那个方案
        return min(ans1, ans2);
    }
};
int main()
{
    vector<int> nums={3,10,7,9,9,3,6,9,4};
    Solution sl;
    cout<<sl.movesToMakeZigzag(nums);
}
