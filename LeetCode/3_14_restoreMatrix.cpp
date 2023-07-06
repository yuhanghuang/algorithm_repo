/*
给你两个非负整数数组 rowSum 和 colSum ，其中 rowSum[i] 是二维矩阵中第 i 行元素的和， colSum[j] 是第 j 列元素的和。换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。
请找到大小为 rowSum.length x colSum.length 的任意 非负整数 矩阵，且该矩阵满足 rowSum 和 colSum 的要求。
请你返回任意一个满足题目要求的二维矩阵，题目保证存在 至少一个 可行矩阵
*/
#include <iostream>  
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int maxrow=0;
        int maxcol=0;
        int temp=0;
        vector<vector<int>> ans(rowSum.size(),vector<int>(colSum.size(),0));
        for(int i=0;i<rowSum.size();i++)
        {
            for(int j=0;j<colSum.size();j++)
            {
                temp=min(rowSum[i],colSum[j]);
                ans[i][j]=temp;
                rowSum[i]-=temp;
                colSum[j]-=temp;
            }
        }
        return ans;

    }
};
int main()
{
    // rowSum = [3,8], colSum = [4,7]
    vector<int> rowsum={3,8};
    vector<int> colsum={4,7};
    Solution sl;
    vector<vector<int>> ans=sl.restoreMatrix(rowsum,colsum);
    vector<int>::iterator it;
    vector<vector<int>>::iterator iter;
    vector<int> temp;
    for(iter=ans.begin();iter!=ans.end();iter++)
    {
        temp =*iter;
        for(it=temp.begin();it!=temp.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }

}