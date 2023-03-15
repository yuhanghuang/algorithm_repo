#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> ans1;
        unordered_map<int,int> ans2;
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        for(int i=0;i<roads.size();i++)
        {
            ans1[roads[i][0]]++;
            ans1[roads[i][1]]++;
            // ans2.emplace(roads[i][0],roads[i][1]);
            connect[roads[i][0]][roads[i][1]] = true;
            connect[roads[i][1]][roads[i][0]] = true;
            // ans2[roads[i][0]]=roads[i][1];
            // ans2[roads[i][1]]=roads[i][0];

        }
        int temp=0;
        int temp1=0;
        int res=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                {
                    // temp1=max(temp,ans1[i]+ans1[j]);
                    temp1=ans1[i]+ans1[j];
                     if(connect[i][j])
                        {
                            res=1;
                        }

                    temp1=temp1-res;
                    temp=max(temp1,temp);
                    res=0;
                }
            }
        }
        return temp;
    }
};

int main()
{
    int n=4;
    vector<vector<int>> roads={{0,1},{0,3},{1,2},{1,3}};
    Solution sl;
    cout<<sl.maximalNetworkRank(n,roads);
}

// 方法二
class Solution1 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> connect(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (auto v : roads) {
            connect[v[0]][v[1]] = true;
            connect[v[1]][v[0]] = true;
            degree[v[0]]++;
            degree[v[1]]++;
        }

        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j] - (connect[i][j] ? 1 : 0);
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};
