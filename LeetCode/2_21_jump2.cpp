/* 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
0 <= j <= nums[i] 
 i + j < n
 返回到达 nums[n - 1] 的最小跳跃次数。
 生成的测试用例可以到达 nums[n - 1]。*/
#include<iostream>
#include<vector>
using namespace std;
/*
方法一
直观上来看，我们可以「贪心」地选择距离最后一个位置最远的那个位置，也就是对应下标最小的那个位置。
因此，我们可以从左到右遍历数组，选择第一个满足要求的位置。
找到最后一步跳跃前所在的位置之后，我们继续贪心地寻找倒数第二步跳跃前所在的位置，以此类推，直到找到数组的开始位置。

class Solution {
public:
    int jump(vector<int>& nums) {
        int target = nums.size()-1 ;
        int steps = 0;
        while(target>0)
        {
            for(int i=0;i<target;i++)
            {
                if(nums[i]+i>=target)
                {
                    target = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;
        
    }
};
*/
// 方法二
class Solution {
public:
    int jump(vector<int>& nums) {
        int target = nums.size()-1 ;
        int end = 0;
        int steps=0;
        int rightmax = 0;
        for(int i=0;i<target;i++)
        {
            if(i<=rightmax)
            {
                rightmax=max(rightmax,i+nums[i]);
                if(i==end)
                {
                    end = rightmax;
                    steps++;
                }
                
            }
        }
    return steps;
        
    }
};

int main()
{
    vector<int> arr={2,3,1,1,4};
    Solution sl;
    printf("%d\n",sl.jump(arr));
}
