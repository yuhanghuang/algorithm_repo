#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//二维数组的遍历
void reverse2(vector<vector<int>> vec)
{
    if(vec.empty())
    {
        cout<<"vector is empty"<<endl;
    }
    vector<int>::iterator it; 
    vector<vector<int>>::iterator iterator;
    vector<int> temp,temp1;
    cout<<"使用迭代器进行遍历"<<endl;
    for(iterator=vec.begin();iterator!=vec.end();iterator++)
    {
        //迭代器其实就是元素的地址
        temp = *iterator;
        for(it=temp.begin();it!=temp.end();it++)
        {
            cout<<*it<<" ";
        }
    }
    cout<<endl;
    for(auto iter:vec)
    {
        for(auto itt:iter)
        {
            cout<<itt<<" ";
        }
    }
    //使用下表进行索引
    cout<<endl;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            cout<<vec[i][j]<<" ";
        }
    }
    // cout<<"-------"<<endl;
}
int main()
{
    vector<vector<int>> vecs={{1,2,3},{4,5,6},{7,8,9}};
    reverse2(vecs);
}