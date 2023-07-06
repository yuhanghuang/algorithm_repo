/*
有两个长度相同的字符串 s1 和 s2，且它们其中 只含有 字符 "x" 和 "y"，你需要通过「交换字符」的方式使这两个字符串相同。
每次「交换字符」的时候，你都可以在两个字符串中各选一个字符进行交换。
交换只能发生在两个不同的字符串之间，绝对不能发生在同一个字符串内部。也就是说，我们可以交换 s1[i] 和 s2[j]，但不能交换 s1[i] 和 s1[j]。
最后，请你返回使 s1 和 s2 相同的最小交换次数，如果没有方法能够使得这两个字符串相同，则返回 -1 。
*/
#include <>  
#include <iostream>  
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
    vector<char> array1={};
    vector<char> array2={};
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])
        {
            array1.push_back(s1[i]);
            array2.push_back(s2[i]);
        }
    }
    int xy=0;
    int yx=0;
    for(int i=0;i<array1.size();i++)
    {
        if((array1[i]=='x') && (array2[i]=='y'))
            xy++;
        if((array1[i]=='y') && (array2[i]=='x'))
            yx++; 
    }
    if ((xy + yx) % 2 == 1) {
            return -1;
        }
    return xy / 2 + yx / 2 + xy % 2 + yx % 2;

    }
};
int main()
{
    string s1="xx";
    string s2="yy";
    Solution sl;
    cout<<sl.minimumSwap(s1,s2);
}