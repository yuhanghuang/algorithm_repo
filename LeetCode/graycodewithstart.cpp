#include<iostream>
#include<vector>
using namespace std;

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
    vector<int> ans1;
    int start =3;
    for(int i=0;i<ans.size();i++)
        ans1.push_back(ans[i]^start);
    return ans1;
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