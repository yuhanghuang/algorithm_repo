#include <iostream>
#include <string>
using namespace std;
int **create(int m,int n){
    int **p;
    p = new int *[m];
    for(int i=0;i<m;i++){
        p[i] = new int[n];
    }
    for(int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        cin >> p[i][j];
    }
    return p;

}

int main(){
    cout << "输入行数与列数"<<endl;
    int M,N;
    cin>>M>>N;
    cout<<endl;
    int **p;
    p=create(M,N);
    for (int i=0;i<M;i++)
    {
        for (int j=0;j<N;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}