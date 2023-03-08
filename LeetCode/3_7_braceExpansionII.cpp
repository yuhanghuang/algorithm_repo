// class Solution {
// public:
//     vector<string> braceExpansionII(string expression) {
//         stack(char) stack1;
//         vector<vector<char>> ans(60,vector<char>(60));
//         int number;
//         int count=0;
//         for(int i=0;i<expression.size();i++)
//         {
//             if(expression[i]=='{')
//             {
//                 number++;
//                 continue;
//                 // stack.push(expression[i]);
//             }
//             if(number!=0)
//             {
//                 vector[count].push_back(expression[i]);
//                 continue;
//             }
//             else
//             {
//                 count++;
//                 continue;
//             }
//             if(expression[i]=='}')
//             {
//                 number--;
//                 if(number==0)
//                 {
//                     count++;
//                 }
//                 continue;
//                 // stack.push('*');
//             }
//         }
//         for(int j=count;j>=0;j--)
//         {
//             for(int i=ans[count].size();i>=0;i--)
//             {

//             }
//         }

//     }
// };
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<sstream>
using namespace std;
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        return vector<string>(s.begin(), s.end());
    }

private:
    set<string> s;

    void dfs(string exp) {
        int j = exp.find_first_of('}');
        if (j == string::npos) {
            s.insert(exp);
            return;
        }
        int i = exp.rfind('{', j);
        string a = exp.substr(0, i);
        string c = exp.substr(j + 1);
        stringstream ss(exp.substr(i + 1, j - i - 1));
        string b;
        while (getline(ss, b, ',')) {
            dfs(a + b + c);
        }
    }
};

int main()
{
    string expression="{a,b}{c,{d,e}}";
    Solution sl;
    vector<string> ans=sl.braceExpansionII(expression);
    // cout<<ans;
    // printf("%s\n",ans);

}
