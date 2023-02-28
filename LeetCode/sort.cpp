#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool cmp_max(int x,int y){
	return x > y;
}
 
int main() {
	int a[] = {8,6,2,9,3,5,4,1,7,10};
 	vector<int> arr(a, a+10);
	sort(arr.begin(),arr.end(),cmp_max); 
 	for(int i = 0; i <arr.size(); ++i){
 		cout <<arr[i] << " ";
	}		 
	return 0 ;
 }