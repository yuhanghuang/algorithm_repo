#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Point{
    int x;
    int y;
};
int main()
{
    vector<Point> pos;
    Point p;
    p.x=1;
    p.y=2;
    pos.push_back(p);
    p.x=3;
    p.y=4;
    pos.push_back(p);
    p.x=6;
    p.y=7;
    pos.push_back(p);
    for(auto i :pos){
        cout<<i.x<<" "<<i.y<<endl;
    }
    vector<string> str;
    str.push_back("hello");
    str.push_back(" ");
    str.push_back("world");
    str.push_back("!\n");
    for(auto i:str){
        cout<<i;
    }
}