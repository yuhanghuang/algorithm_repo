#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        int m1=stones[n-1]-stones[0]+1-n;
        int mt=min(stones[1]-stones[0]-1,stones[n-1]-stones[n-2]-1);
        int max_count=m1-mt;//最大移动次数的理想情况就是每次只让端点距离减小一
        //开始计算最小的移动次数 需要使用滑动窗口或者双指针来实现
        //因为这个数组一共拥有n个元素 每次枚举左端点 从左端点i开始到i+n-1为止为该范围 计算不在此范围的元素数量为m 那么该情况下在左端点为i的情况下移动的的次数\
        是n-m-1此，一次枚举所有的左端点元素 所有值的最小值就是移动的最小次数
        int j=0;
        int temp=0;
        int min_count=stones[n-1]-stones[0]+1;
        for(int i=0;i<n;i++)  //枚举左端点元素
        {
            // j=i+1;
            temp=0;
            while(j+1<n && stones[j+1]-stones[i]<=n-1)
            {
                temp++;
                j++;
            }
            int cost=n-(j-i+1);
            if(j-i+1==n-1 && stones[j]-stones[i]+1==n-1)
                cost=2;
            min_count=min(min_count,cost);
        }
        // for(i = 0; i < n; ++i)
        // {
        //     while(j + 1 < n && stones[j + 1] - stones[i] + 1 <= n)
        //         ++j;
        //     int cost = n - (j - i + 1);
        //     if(j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1)
        //         cost = 2;
        //     mi = min(mi, cost);
        // }

    return vector<int>{min_count,max_count};
    }
};

int main()
{
    Solution sl;
    vector<int> stones={7,4,9};
    sl.numMovesStonesII(stones);

}