#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int commonFactors(int a, int b) {
        int num=0;
        for(int i=1;i<=min(a,b);i++)
        {
            if(a%i==0 && b%i==0)
                num++;
        }
        return num;
        
    }
};

int main()
{
    int a=12;int b=6;
    Solution sl;
    cout<<sl.commonFactors(a,b);
    int c;
    int d;
    cin>>c>>d;
    // cout<sl.commonFactors(c,d);
    printf("%d\n",sl.commonFactors(c,d));
}