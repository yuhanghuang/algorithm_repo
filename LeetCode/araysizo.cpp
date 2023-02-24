#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int steps=0;
        int temp=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[nums.size()-1]==0)
                break;
            if(nums[i]!=0)
            {
                temp=nums[i];
                steps++;
                for(int j=i;j<nums.size();j++)
                {
                    nums[j]=nums[j]-temp;
                }
            }

        }
        return steps;
        
    }
};
int main()
{
    vector<int> array={0,1,5,3,5};
    Solution sl;
    cout<<sl.minimumOperations(array);
}
