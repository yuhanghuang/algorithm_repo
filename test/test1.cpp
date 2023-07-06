#include <iostream>

using namespace std;
struct abc{
    int a,*b;
}*p;
int x[]={6,7},y[]={8,9};

int main()
{
    abc a[]={20,x,30,y};
    p=a;
    cout<<*p->b<<endl;
    cout<<(*p).a<<endl;
    cout<<(++p)->a<<endl;
    cout<<++(*p).a<<endl;
    return 0;
}