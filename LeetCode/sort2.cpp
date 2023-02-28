#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

 bool cmp(vector<int>&a,vector<int>&b){
      if(a[0]!=b[0]) return a[0]<b[0];
      else return a[1]>b[1];
  }

int main(){
    int ans[6]={5,7,3,8,1,2};
    vector<int>num;
    cout<<"before sorted: ";
    for(int i=0;i<6;i++)
    {
        cout<<ans[i]<<" ";
        num.emplace_back(ans[i]);
    }
    cout<<endl;
    cout<<"after sorted: ";
    vector<int> array={5,7,3,8,1,2,6,0,77};
    // vector<int> arra3={{1,5},{6,7},{3,8},{4,0}};
     vector<int> array3={5,7,3,8,1,2,6,0,77};
     vector<vector<int>> arr4={{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
     sort(arr4.begin(),arr4.end(),cmp);
    //按升序排序s
    sort(num.begin(),num.end());
    sort(array.begin(),array.end());
    sort(array3.rbegin(),array3.rend());
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    cout<<"升序排序"<<endl;
    vector<int> array2(ans,ans+6);
    for(int j=0;j<array.size();j++)
    {
        cout<<array[j]<<" ";
    }
    cout<<endl;
    cout<<"降序排序"<<endl;
    for(int j=0;j<array3.size();j++)
    {
        cout<<array3[j]<<" ";
    }
    cout<<"二维数组排序 第一列升序 第二列降序"<<endl;

    for(int j=0;j<arr4.size();j++)
    {
        for(int k=0;k<arr4[j].size();k++)
        {
            cout<<arr4[j][k]<<" ";
        }
        cout<<endl;
    }
    system("pause");
	return 0;
} 

