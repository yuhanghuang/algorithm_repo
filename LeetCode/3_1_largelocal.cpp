#include <string>  
#include <iostream>  
#include <vector>
#include<algorithm>
using namespace std;

int returnmax(vector<vector<int>>& grid,int s,int t)
    {
        int max1=0;
        for(int i=s;i<=s+2;i++)
        {
            for(int j=t;j<=t+2;j++)
            {
                max1=max(max1,grid[i][j]);
            }
        }
        return max1;
    }
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> maxLocal(grid.size()-2,vector<int>(grid.size()-2,0));
        for(int j=0;j<grid.size()-2;j++)
        {
            for(int i=0;i<grid.size()-2;i++)
            {
                maxLocal[j][i]=returnmax(grid,j,i);
            }
        }
        return maxLocal;
    }

    
};

int main()
{
    vector<vector<int>> items1= {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    vector<vector<int>> ans1(items1.size()-2,vector<int>(items1.size()-2,0));
    Solution sl;
    ans1=sl.largestLocal(items1);
    cout<<endl;
    for(auto it:ans1)
    {
        for(auto is:it)
            cout<<is<<" ";
            cout<<endl;
    }
}