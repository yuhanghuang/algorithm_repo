/*给你一个大小为 rows x cols 的矩阵 mat，其中 mat[i][j] 是 0 或 1，请返回 矩阵 mat 中特殊位置的数目 。

特殊位置 定义：如果 mat[i][j] == 1 并且第 i 行和第 j 列中的所有其他元素均为 0（行和列的下标均 从 0 开始 ），则位置 (i, j) 被称为特殊位置。
*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int numSpecial(vector<vector<int>>& mat);

int main()
{
    vector<vector<int>> vec1={{1,0,0},{0,0,1},{1,0,0}};
    // vec1[0]={1,0,0};
    // vec1[1]={0,0,1};
    // vec1[2]={1,0,0};
    cout<<numSpecial(vec1);
}

int numSpecial(vector<vector<int>>& mat) {
    int total=0;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]==1)
            {
                int temp1=0;
                int temp2=0;
                for(int s=0;s<mat.size();s++)
                {
                    temp1+=mat[s][j];
                }
                for(int t=0;t<mat[0].size();t++)
                {
                    temp2+=mat[i][t];
                }
                if(temp1==1 && temp2==1)
                {
                    total++;
                }
            }
        }
        }
    return total;

}