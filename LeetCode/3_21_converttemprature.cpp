#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kev=celsius+273.15;
        double fah=celsius*1.80+32.00;
        vector<double> ans;
        ans.push_back(kev);
        ans.push_back(fah);
        return ans;
        
    }
};
int main()
{
    Solution sl;
    vector<double> ans=sl.convertTemperature(35.50);
    for(auto &it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(vector<double>::iterator it=ans.begin();it!=ans.end();it++)
    {
        cout<<*it<<" ";
    }
}