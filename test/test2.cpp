#include<iostream>
using namespace std;

template<class T>
T max_value(T x, T y, T z){
	T temp;
	if(x>y) temp=x;
	else temp=y;
	if(z>temp) temp=z;
	return temp;
}

class Circle{
private:
	int x, y;
	double radius;
public:
	Circle(int a=0, int b=0, double c=0.0){
		x=a;
		y=b;
		radius=c;
	}
	friend ostream& operator<<(ostream& out, Circle& C){
		out<<"x="<<C.x<<" y="<<C.y<<" radius="<<C.radius;
		return out;
	}
	int operator>(Circle& C){
		if(radius>C.radius){
			return 1;
		}
		return 0;
	}
};

int main(){
	Circle c1(2,3,5),c2(3,5,8),c3(3,2,6);
	cout<<max_value(12,23,21)<<endl;
	cout<<max_value('a','b','9')<<endl;
	cout<<max_value(c1,c2,c3)<<endl;	//出现错误，在第一个<<运算符上，错误提示：没有与这些操作数匹配的"<<"运算符
	return 0;
}
