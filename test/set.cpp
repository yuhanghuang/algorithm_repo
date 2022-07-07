#include <iostream>
#include <set>
using namespace std;
struct Info
{
    string name;
    double value;
    bool operator < (const Info &info) const
    {
        return info.value<value;
    }
};

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(2);
    s.insert(1);
    for (auto i:s){
        cout<<i;
    }
    cout<<endl;
    for(set<int>::iterator i=s.begin();i!=s.end();i++){
        cout<<*i;
    }
    cout<<"set的size的值为"<<s.size()<<endl;
    cout<<"set的maxsize的值是"<<s.max_size()<<endl;
    cout<<"set的第一个元素是"<<*s.begin()<<endl;
    cout<<"set的最后一个元素是"<<*s.end()<<endl;
    // s.clear();
    // if (s.empty()){
    //     cout<<"set为空"<<endl;
    // }
    cout<<"set的值为"<<s.size()<<endl;
    cout<<"set的maxsize值是"<<s.max_size()<<endl;
    /*
     *count() :用来查找set中某个元素出现的次数。这个函数在set并不是很实用，因为一个键值在set只可能出现0或1次，这样就变成了判断某一键值是否在set出现过了。

     find(): 用来查找set中某个元素出现的位置。如果找到，就返回这个元素的迭代器，如果这个元素不存在，则返回 s.end() 。 (最后一个元素的下一个位置，s为set的变量名)
     * 
     */
    cout << "-------"<<endl;
    cout<<"输出是否存在1"<<endl;
    cout<<s.count(1)<<endl;
    cout<<"输出2及以后的元素"<<endl;
    set<int>::iterator iter;
    iter = s.find(2);
    for(set<int>::iterator it=iter;it!=s.end();it++)
    {
        cout<<*it<<endl;
    }

    //不得不提的就是结构体类型（struct ）的set ，使用时必须要重载 ‘<’ 运算符
    set<Info> s1;
    Info info;
    info.name="hyh";
    info.value=90;
    s1.insert(info);
    info.name="hhh";
    info.value=58;
    s1.insert(info);
    info.name="zsd";
    info.value=37;
    s1.insert(info);
    set<Info>::iterator it;
    for (it=s1.begin();it!=s1.end();it++)
    {
        cout<<(*it).name<<" : "<<(*it).value<<endl;
    }
    return 0;
}