#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>
using namespace std;

int main() {
    
    vector<int> vec1;
    int length =vec1.empty();  //length是1,不是0
    //设定数组的默认长度为10
    vector<int> data(10);
    //设置数组长度为10且的给定初始值为1
    vector<int> data1(10,1);
    //直给定数据
    vector<int> data2 ={1,5,6,3};
  /**
    copy(A.begin(),A.end(),B.begin()+1); //把A中的从A.begin()（包括它）到A.end()（不包括它）的元素复制到B中，从B.begin()+1的位置（包括它）开始复制，覆盖掉原有元素
    find(A.begin(),A.end(),10); //在A中的从A.begin()（包括它）到A.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置
   **/
    //设置二维数组长度为5行，4列，默认值是0
    vector<vector<int>> data3(5,vector<int>(4));
    //设置二维数组长度为5行，4列，默认值是1
    vector<vector<int>> data4(5,vector<int>(4,1));
    //直接给定数据
    vector<vector<int>> data5 = {{1,4,5,6},{4,2}};
    int m=8;
    vector<vector<int> > array(m); //m表示的是初始化大小=array.size()，而不是初始值
    //初始化一个m*n的二维数组
    for(int i=0;i<m;i++) 
    {
        array[i].resize(5);
    }
    int N,M;
    cin >> N;
    while(N--){
        cin >> M;
        vec1.push_back(M);
    }
    for (int i =0;i<vec1.size();i++)
    {
        // cout << vec1[i]<<endl;
    }
    //vector初始化
    vector<int>a{2,5,1,4,6};
    //begin为指向待sort()的数组的第一个元素的指针，end为指向待sort()的数组的最后一个元素的下一个位置的指针，\
    cmp参数为排序准则，如果没有的话，默认以非降序排序
    /** begin() 返回一个迭代器（iterator），指向vector地第一个元素
    end() 返回一个迭代器，指向vector的最后一个元素的后一个位置
    rbegin() 返回一个迭代器，即reverse 的begin() 指向最后一个元素
    rend(） 返回一个迭代器， 指向第一个元素的前一个位置
    **/
    //正向排序
    sort(a.begin(),a.end());  
    //逆向排序  也可以用于字符串
    reverse(a.begin(),a.end());
    string str="www.mathor.top";
    reverse(str.begin(),str.end());//str结果为pot.rohtam.wwww

    //特定位置插入 删除
    auto k =a.begin();
    vector<int>::iterator k1=a.begin();
    cout<<"输出:"<<endl;
    a.insert(k,3);
    a.insert(k1,3);
    // a.erase(k);
    a.pop_back();
    sort(vec1.begin(),vec1.end());
    for (auto i :vec1){
        // cout<<i<<endl;
    }
    for (auto i :a){
        cout<<i<<endl;
    }
    for (int j=0;j<a.size();j++){
        cout<<a[j]<<endl;
    }
    return 0;
}