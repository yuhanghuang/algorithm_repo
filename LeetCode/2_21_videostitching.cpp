/*你将会获得一系列视频片段，这些片段来自于一项持续时长为 time 秒的体育赛事。这些片段可能有所重叠，也可能长度不一。
使用数组 clips 描述所有的视频片段，其中 clips[i] = [starti, endi] 表示：某个视频片段开始于 starti 并于 endi 结束。
甚至可以对这些片段自由地再剪辑：
例如，片段 [0, 7] 可以剪切成 [0, 1] + [1, 3] + [3, 7] 三部分。
我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0, time]）。返回所需片段的最小数目，如果无法完成该任务，则返回 -1 。
*/
#include<iostream>
#include<vector>
using namespace std;
// /方法一 动态规划
/*
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time+1,INT_MAX - 1);
        dp[0] = 0;
        for(int i=0;i<=time;i++)
        {
            for(int j=0;j<clips.size();j++)
            {
                if(clips[j][0]<=i && clips[j][1]>=i)
                {
                    dp[i]=min(dp[i],dp[clips[j][0]]+1);
                }
            }



        }
        if(dp[time]==INT_MAX - 1)
            return -1;
        else
            return dp[time];
        
    }
};
*/
//方法二
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int last = 0;
        int pre = 0;
        int steps =0;
        vector<int> maxn(time);//默认初始值为0
        for(int i=0;i<clips.size();i++)
        {
            if(clips[i][0]<time)
            // if(clips[i][0]<=time)会报错
            {
            maxn[clips[i][0]] = max(maxn[clips[i][0]],clips[i][1]);
            }
        }

        for(int i=0;i<time;i++)
        {
            last = max(last,maxn[i]);
            if(i==last)
                return -1;
            // if(*max_element(maxn.begin,maxn.end)<time) 找vector的最大元素
            // return -1;
            if(i==pre)
            {
                steps++;
                pre=last;
            }
        }
        return steps;
        
    }
};
// [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]
int main()
{
    vector<vector<int>> arr={{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    Solution sl;
    printf("%d\n",sl.videoStitching(arr,10));

}
