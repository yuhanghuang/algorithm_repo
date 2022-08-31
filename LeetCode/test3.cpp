/*给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。
示例 1：
输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
*/
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;


    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int begin =0;
        int end =0;
        int index = 0;
        int i;
        vector<int> vec1;
        for(i=0;i<popped.size();i++)
        {
            if(count(vec1.begin(),vec1.end(),popped[i])){
                continue;
            }
            if(popped[i]==(*(pushed.end()-1)))
            {
                if(i==0){
                    for(int ss=0;ss<pushed.size();ss++){
                        if(pushed[ss]!=popped[pushed.size()-i-1])
                        return false;
                    }
                    return true;
                }
                vec1.push_back(popped[i]);
                break;
            }
            index = find(pushed.begin(),pushed.end(),popped[i])-pushed.begin();
            end = index;
            for(int j=begin;j<=end;j++){
                vec1.push_back(pushed[j]);
            }
            begin = index+1;
            
        }

        for(int s=i+1;s<popped.size()-1;s++)
        {
            if(popped[s]<popped[s+1]){
                return false;
            }
        }
        if(vec1.size()!=pushed.size() || vec1.size()!=popped.size()){
            return false;
        }
        for(int m=0;m<pushed.size();m++){
            if(pushed[m]!=vec1[m]){
                return false;
            }
        }

        return true;
        }

        int main() {
            vector<int> v1,v2;
            // vector<int> vec1;
            v1.push_back(1);
            v1.push_back(2);
            v1.push_back(0);

            v2.push_back(0);
            v2.push_back(2);
            v2.push_back(1);
            validateStackSequences(v1,v2);
            // for(int t=0;)
            // cout << vec1<<endl;
            
}



// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int> st;
//         int n = pushed.size();
//         for (int i = 0, j = 0; i < n; i++) {
//             st.emplace(pushed[i]);
//             while (!st.empty() && st.top() == popped[j]) {
//                 st.pop();
//                 j++;
//             }
//         }
//         return st.empty();
//     }
// };