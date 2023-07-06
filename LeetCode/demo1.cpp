#include<iostream>
using namespace std;


class A
{
    int a,b;
public:
    A(int i=3,int j=4):a(i),b(j){}
    A operator*=(int i);
    void show(){cout<<a<<" "<<b;}
    // ~A();
};

A A::operator*=(int i)
{
    this->a*=i;
    this->b*=i+1;
    return *this;
}

int main()
{
    A o1(2);
    (o1*=3).show();
    return 0;
}