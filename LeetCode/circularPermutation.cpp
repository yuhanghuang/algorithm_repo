#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
    vector<int>m;
    for(int i =15; i>=0; i--)
    {
        m.push_back( ( (start>>i) & 1) );//与1做位操作，前面位数均为0
        //cout<<( (n>>i) & 1);//输出二进制
    }

    }
};

int main()
{
    int start =5;
    vector<int> m;
    for(int i =15; i>=0; i--)
    {
        m.push_back( ( (start>>i) & 1) );//与1做位操作，前面位数均为0
        cout<<( (start>>i) & 1);//输出二进制
    }
    cout<<endl;
    int flag=0;
    for(int i=0;i<16;i++)
    {
        if(m[i]!=0)
            flag=1;
        if(flag)
         cout<<m[i]<<endl;
    }
    return 0;
}