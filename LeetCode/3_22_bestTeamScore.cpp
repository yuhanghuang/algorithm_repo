#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // unordered_map<int,int> res;
        // vector<vector<int>> ans(ages.size(),vector<int>(ages.size(),0));
        // for(int i=0;i<ages.size();i++)
        // {
        //     ans[ages][]
        // }
        vector<pair<int,int>> res;
        for(int i=0;i<ages.size();i++)
        {
            res.push_back({scores[i],ages[i]});
        }
        int ans=0;
        vector<int> dp(ages.size());//dp[i]表示當前人為i的最好成績之和
        sort(res.begin(),res.end());//分數升序
        for(int i=0;i<ages.size();i++)
        {
            dp[i]=res[i].first;
            for(int j=0;j<i;j++)
            {
                if(res[j].second<=res[i].second)
                {
                    dp[i]=max(dp[i],dp[j]+res[i].first);
                }
                
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    vector<int> scores={1,3,18,10,15};
    vector<int> ages={1,2,8,6,5};
    cout<<sl.bestTeamScore(scores,ages)<<endl;
}