//题目：给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。\
如果存在，返回 true ；否则，返回 false 。
//但是错误使用了插入，用成了emplace，导致两个例子没有通过，由于要求abs(i-j)<=k，因此肯定需要序列更大的与当前的判断是否符合，\
如果使用emplace则不会更新，会停留在最前面的，因此错误。应当使用dict[num]=i这种方式更新。
//使用emplace插入两个key相同的，emplace是拒绝插入的！！所以只会显示第一个1,1，indert与emplace的插入效果一样是拒绝插入的所以只可以使用赋值来进行插入。
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int num = 0;
        unordered_map<int,int> dict;
        int length = nums.size();
        for(int i=0;i<length;i++)
        {
            num = nums[i];
            if(dict.count(num)&&abs((dict.find(num))->second-i)<=k)
            {
                return true;
            }
            dict[num]=i;
        }
        return false;
    }
};

int main()
{
    Solution sl;
    vector<int> nums={1,2,3,4,5,1,5,1,2,6,1,8};
    cout<<sl.containsNearbyDuplicate(nums,7);
}

// emplace插入
unordered_map<int, int> dict;
	dict.emplace(1, 1);
	dict.emplace(1, 2);
	unordered_map<int, int>::iterator iter;
	for (iter = dict.begin();iter != dict.end();iter++)
	{
		cout <<"key: " << iter->first << " value: " << iter->second << endl;
	}

//赋值插入
unordered_map<int, int> dict;
	dict[1]=1;
	dict[1]=2;
	unordered_map<int, int>::iterator iter;
	for (iter = dict.begin();iter != dict.end();iter++)
	{
		cout <<"key: " << iter->first << " value: " << iter->second << endl;
	}

    //insert插入
    unordered_map<int, int> dict;
	dict.insert(pair<int,int>(1,1));
	dict.insert(pair<int, int>(1, 2));
	unordered_map<int, int>::iterator iter;
	for (iter = dict.begin();iter != dict.end();iter++)
	{
		cout <<"key: " << iter->first << " value: " << iter->second << endl;
	}