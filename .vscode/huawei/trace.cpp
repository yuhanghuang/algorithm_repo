//有一个核心交易系统接口被N个上游系统调用，每个上游系统的调用量R=[R1,R2,...,RN],由于核心交易系统集群故障，需要暂时系统降级限制调用，\
核心交易系统能接受的最大调用量为cnt。设置降级规则如下:如果sum(R1,R2,...,RN)小于等于cnt，则全部可以正常调用，返回-1;如果sum(R1,R2....,RN)大于ent，\
议置一个闻值imit，如果某个上游系统发起的调用量超过limit，就将该游家本的调用量限制为limit，其余未达到limit的系统可以正常发起调用。\
求叫这最大的imit (limit可以为0)。此题目对效率有要求，请选择高效的力

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int nums;
    vector<int> num;
    while (cin>>nums)
    {
        num.push_back(nums);
        char c = cin.get();
        if(c=='\n' || c==EOF)
        {
            break;
        }
    }
    // int maxValue = *max_element(num.begin(),num.end());
    int sum=0;
     for(auto it:num)
     {
        sum=sum+it;
     }
     int temp=sum;
    vector<int> num1;
    vector<int> ans;
    while (cin>>nums)
    {
        num1.push_back(nums);
        char c = cin.get();
        if(c=='\n' || c==EOF)
        {
            break;
        }
    }
    sum=0;
     for(auto it:num1)
     {
        sum=sum+it;
     }
    // cout<<temp;
    // cout<<sum;
    int count=0;
    int limit=0;
    int maxValue=0;
    while(++limit){
    for(auto it:num)
    {
        if(it<=limit)
        {
            count+=it;
        }
        else
        {
            count+=limit;
        }
    }
    if(count<=sum)
        {
            ans.push_back(limit);
        }
    vector<int> v;
    maxValue = *max_element(num.begin(),num.end());
    if(limit>maxValue)
        {
            break;
        }
    count=0;
    }
    if(!ans.empty()) 
    {
        cout<<*max_element(ans.begin(),ans.end());
    }
    else
    {
        cout<<0;
    }
}
