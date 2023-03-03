#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;
// 
class Solution1 {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> h;
        vector<string> ans;
        for(int i=0;i<names.size();i++)
        {
            h[names[i]]++;

        }
        if(h.size()==names.size())
            return names;
        else
            {
                for(auto kv:h)
                {
                    if(kv.second-1)
                    {
                        int count=1;
                        while(count++)
                        {
                          if((h[addSuffix(kv.first,count)])>=1)
                          {
                              continue;
                          }
                          else
                          {
                              h[addSuffix(kv.first,count)]=1;
                              kv.second--;
                              break;
                          }
                        }
                    }

                }
            }
        for(auto kv:h)
        {
            ans.emplace_back(kv.first);
        }
        return ans;
    }
    string addSuffix(string name, int k) {
        return name + "(" + to_string(k) + ")";
    }   
};

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> h;
        vector<string> ans;
        for(auto &temp:names)
        {
            if(!h.count(temp))
            {
                h[temp]=1;
                ans.emplace_back(temp);
            }
            else
            {
                int k=h[temp];
                while(h.count(addSuffix(temp,k)))
                {
                    k++;
                }
                ans.emplace_back(addSuffix(temp,k));
                h[addSuffix(temp,k)]=1;
                h[temp]=k+1;
            }
        }

        return ans;

    }   
   string addSuffix(string name, int k) {
        return name + "(" + to_string(k) + ")";
   }

};
int main()
{
    vector<string> names={"gta","gta(1)","gta","avalon"};
    Solution sl;
    Solution1 s2;
    // cout<<sl.getFolderNames(names);
    printf("%s",sl.getFolderNames(names));
     printf("%s",s2.getFolderNames(names));
}