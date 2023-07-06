#include <string>  
#include <iostream>  
#include <vector>
#include<algorithm>
using namespace std;


bool compare(vector<int>&a,vector<int>&b){
      if(a[0]!=b[0]) return a[0]<b[0];
      else return a[1]>b[1];
  }

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans(items1.size(),vector<int>(2,0));
        int count=0;
        for(int i=0;i<items1.size();i++)
        {
            for(int j=0;j<items2.size();j++)
            {
                if(items1[i][0]==items2[j][0])
                {

                    ans[count][0]=items1[i][0];
                    ans[count][1]=items1[i][1]+items1[j][1];
                    count++;
                    break;
                }
            if(j==(items2.size()-1))
            {
                ans[count][0]=items1[i][0];
                ans[count][1]=items1[i][1];
                count++;
            }

            }
        }
        // sort(ans.begin(),ans.end(),compare);
        sort(ans.begin(),ans.end(),compare2);
        return ans;
    }

     bool compare2(vector<int>&a,vector<int>&b){
      if(a[0]!=b[0]) 
        return a[0]<b[0];
      else 
        return a[1]>b[1];
  }
};


int main()
{
    vector<vector<int>> items1= {{1,3},{2,2},{7,6}};
    vector<vector<int>> items2= {{7,1},{2,2},{1,4}};
    Solution sl;
    vector<vector<int>> ans2=sl.mergeSimilarItems(items1,items2);
    for(auto i:ans2)
    {
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;

}
/*
有些语言可以在维护键值对的同时，对键值对按照「键」进行排序，比如 C++ 中的 std::map这样我们可以省略掉最后对数组的排序过程。
/*
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (auto &v : items1) {
            mp[v[0]] += v[1];
        }
        for (auto &v : items2) {
            mp[v[0]] += v[1];
        }

        vector<vector<int>> res;
        for (auto &[k, v] : mp) {
            res.push_back({k, v});
        }
        return res;
    }
};
*/