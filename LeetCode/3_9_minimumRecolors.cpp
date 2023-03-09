#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // int ans=0;
        vector<int> ans(blocks.size(),0);
        // vector<vector<int>> ans(blocks.size()+1,vector<int>(k,0));
        for(int i=0;i<=blocks.size()-k;i++)
        {
            for(int j=i;j<i+k;j++)
            {
                if(blocks[j]=='B')
                {
                    ans[i]++;
                }
            }
        }
        int max1=0;
        for(int i=0;i<blocks.size();i++)
        {
            max1=max(max1,ans[i]);
        }
        // sort(ans.begin(),ans.end());//降序
        sort(ans.rbegin(),ans.rend());//升序
        return k-ans[0];
        // return k-max1;

    }

};
// 方法二 滑动窗口
class Solution2 {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0, cnt = 0;
        while (r < k) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            r++;
        }
        int res = cnt;
        while (r < blocks.size()) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            cnt -= blocks[l] == 'W' ? 1 : 0;
            res = min(res, cnt);
            l++;
            r++;
        }
        return res;
    }
};

int main()
{
    Solution sl;
    string blocks("WBBWWBBWBW");
    int k=7;
    cout<<sl.minimumRecolors(blocks,k);
}