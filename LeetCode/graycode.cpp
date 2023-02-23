#include<iostream>
#include<vector>
using namespace std;
// 方法一
/*
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1 << n);
        for (int i = 0; i < ret.size(); i++) {
            ret[i] = (i >> 1) ^ i;
        }
        return ret;
    }
};
*/
/* 方法二镜像反射法https://leetcode.cn/problems/gray-code/solution/gray-code-jing-xiang-fan-she-fa-by-jyd/
Gn'是Gn的最高位加上0，因此转化为10进制数的话二者是完全相同的，即Gn=Gn'
因为Rn是Gn的镜像因此Rn就是Gn的逆向遍历，在最高位上加上1，即加上(2^i，i为当前遍历数字的位数)
再将Gn与Rn'进行拼接就是我们所需要的格雷编码的值。

*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans={0};
        for(int i=0;i<n;i++){
            int num = 1 << i;  
            int size = ans.size();
            for(int j =size-1;j>=0;j--){  // 反向遍历
                ans.push_back(ans[j] + num);  // 相当于在前缀加1
            }
        }
        return ans;
    //      vector<int> ans1;
    //      int start =3;
    // for(int i=0;i<ans.size();i++)
    //     ans1.push_back(ans[i]^start);
    // return ans1;
    }
};
int main()
{
    vector<int> arr;
    Solution sl;
    arr = sl.grayCode(2);
    for(int i=0;i<arr.size();i++)
        cout <<arr[i]<<endl;
}