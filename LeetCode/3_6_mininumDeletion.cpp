// class Solution {
// public:
//     int minimumDeletions(string s) {
//         vector<int> count1(s.size(),0);
//         for(int i=0;i<s.size();i++)
//         {
            
//                 for(int j=0;j<i;j++)
//                 {
//                     if(s[j]=='b')
//                         count1[i]++;
//                 }
//                 for(int j=i+1;j<s.size();j++)
//                 {
//                     if(s[j]=='a')
//                         count1[i]++;
//                 }
 
//         }
//         int max1=10000;
//         for(int i=0;i<count1.size();i++)
//             max1=min(max1,count1[i]);
//         return max1;

//     }
// };
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> count1(s.size()+1,0);
        for(int j=0;j<s.size();j++)
            {
                if(s[j]=='a')
                    count1[0]++;
            }
        int temp=count1[0];
        for(int k=1;k<=s.size();k++)
        {
            if(s[k-1]=='a')
            {
                count1[k]=count1[k-1]-1;
            }
            else
            {
                count1[k]=count1[k-1]+1;
            }
        }
        int max1=100000000;
        for(int i=0;i<count1.size();i++)
            max1=min(max1,count1[i]);
        return max1;

    }
};

int main()
{
    string s("aababbab");
    Solution sl;
    cout<<sl.minimumDeletions(s);
}
// 方法二优化
// https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/solution/qian-hou-zhui-fen-jie-yi-zhang-tu-miao-d-dor2/
class Solution1 {
public:
    int minimumDeletions(string s) {
        int del = 0;
        for (char c : s)
            del += 'b' - c; // 统计 'a' 的个数
        int ans = del;
        for (char c : s) {
            // 'a' -> -1    'b' -> 1
            del += (c - 'a') * 2 - 1;
            ans = min(ans, del);
        }
        return ans;
    }
};
