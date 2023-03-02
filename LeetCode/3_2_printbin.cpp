#include <string>  
#include <iostream>  
#include <vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    string printBin(double num) {
    vector<int> ans(32,0);
    string s;
    int end;
    for(int i=0;i<32;i++)
    {
        if((num-pow(0.5,i+1))>=0)
        {
        ans[i]=1;
        num=num-pow(0.5,i+1);
        }
        if(num==0)
        {
            end=i;
            break;
        }
    }
    if(num>0)
    {
        return "ERROR";
    }
    // cout<<"0.";
    string temp="0.";
    s.insert(0,temp);
    for(int j=0;j<=end;j++)
    {
        s.insert(j+2,to_string(ans[j]));
    }
        
    return s;
}
};

int main()
{
    double num=0.625;
    Solution sl;
    cout<<sl.printBin(num);
}