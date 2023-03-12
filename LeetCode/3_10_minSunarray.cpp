// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p) {
//         int sum1;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum1+=nums[i];
//         }
//         int res=sum1 % p;
//         if(res==0) return 0;
//         sort(nums.begin(),nums.end());
//         int begin=0;
//         int end=0;
//         int step=0;
//         // for(int i=begin;i<nums.size();i++)
//         while(begin<=(nums.size()-1))
//         {
//             while(end<=nums.size())
//             {
//                 if(res==nums[end])
//                 {
//                     ++step;
//                     return step;
//                 }
//                 else if(res>nums[end])
//                 {
//                     res=res-nums[end];
//                     end++;
//                     step++;
//                 }
//                 else
//                 {
//                     end++;
//                     continue;
//                 }
//             }
//             begin++;
//         }
//         return -1;
//     }
// };
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<int> array(nums.size()+1,0);
        array[0]=0;
        int sums=0;
        for(int i=0;i<nums.size();i++)
        {
            // sums+=nums[i]; 会出现溢出的情况
            // array[i+1]=sums%p;
            array[i+1]=(array[i]+nums[i])%p;
        }
        int target=array[nums.size()];
        if(target==0) return 0;
        unordered_map<int,int> ans;
        int result=nums.size();
        for(int i=0;i<=nums.size();i++)
        {
            ans[array[i]]=i;
            auto it=ans.find((array[i]-target+p)%p);
            int index=find(array.begin(),array.end(),(array[i]-target+p)%p)-array.begin();
            if(i>=index)
            {

                result=min(result,i-index);
            }
            // if(it!=ans.end())
            // {
            //     result=min(result,i-it->second);
            // }
        }
        return result<nums.size()? result:-1;

        // int sum1;
        // for(int i=0;i<nums.size();i++)
        // {
        //     sum1+=nums[i];
        // }
        // int res=sum1 % p;
        // if(res==0) return 0;
        // sort(nums.begin(),nums.end());
        // int begin=0;
        // int end=0;
        // int step=0;
        // // for(int i=begin;i<nums.size();i++)
        // while(begin<=(nums.size()-1))
        // {
        //     while(end<=nums.size())
        //     {
        //         if(res==nums[end])
        //         {
        //             ++step;
        //             return step;
        //         }
        //         else if(res>nums[end])
        //         {
        //             res=res-nums[end];
        //             end++;
        //             step++;
        //         }
        //         else
        //         {
        //             end++;
        //             continue;
        //         }
        //     }
        //     begin++;
        // }
        // return -1;
    }
};
// https://leetcode.cn/problems/make-sum-divisible-by-p/solution/tao-lu-qian-zhui-he-ha-xi-biao-pythonjav-rzl0/
int main()
{
    // vector<int> nums={6,3,5,2};
    vector<int> nums={3,1,4,2};
    Solution sl;
    // cout<<sl.minSubarray(nums,9);
    cout<<sl.minSubarray(nums,6);
}