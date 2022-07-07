#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    //二维动态数组创建
    vector<vector<int>> vec2;
    // vector<vector<str>>vec2;
    //一维数组创建
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);
    vec1.push_back(2);
    vec2.push_back(vec1);
    vec1.clear();
    vec1.push_back(4);
    vec2.push_back(vec1);
    for (auto i :vec2){
        for (auto j:i){
            cout << j<< " ";
        }
        cout<<endl ;
    }
    cout<<"\n"<<endl;
    cout << "------" << endl;
    for(int i = 0; i < vec2.size(); ++i){
        for(int j = 0 ; j< vec2[i].size(); ++j){
            cout << vec2[i][j] << "  ";
        }
        cout << endl ;
    }
}