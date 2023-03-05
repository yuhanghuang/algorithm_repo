#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// class Solution {
// public:
//     int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
//         int total=0;
//         int dex=0;
//         int maxcount=0;
//         int numbers=1;
//         int count=0;
//         int flag=0;
//         vector<vector<int>> array;
//         for(int i=0;numbers!=0;i++)
//         {

//             flag=1;
//             if(i==0)
//                 numbers=customers[i];
//             else if(i>=customers.size());
//             else
//             {
//                 numbers+=customers[i];
//             }
            
//             if(numbers<=4)
//             {
//                 total+=numbers*boardingCost-runningCost;
//                 maxcount=max(total,maxcount);
//                 if(maxcount==total)
//                 {
//                     count++;
//                     dex=count;
//                 }
//                 else
//                 {
//                     count++;
//                 }
//                 numbers-=numbers;
//             }
//             else
//             {
//                 count++;
//                 numbers-=4;
//                 total+=4*boardingCost-runningCost;
//                 maxcount=max(total,maxcount);
//                 dex=count;
//             }
//         }
//         if(total<=0)
//             return -1;
//         return dex;

//     }
// };
// 
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n=customers.size();
        // i表示第几次轮转（设置了从0开始），ans用于保存结果，sum保存目前的利润（可能为负），maxn保存目前最大的利润，lest保存还剩下多少个顾客
        int i=0,ans=-1,maxn=0,sum=0,lest=0;    
        // 由于一开始轮转的时候，每轮都会有顾客加入，所以先使用for循环，保存利润最大的轮次
        for(;i<n;i++){
            lest+=customers[i];
            sum+=min(lest,4)*boardingCost-runningCost;
            if(sum>maxn){
                maxn=sum;
                ans=i+1;
            }
            lest-=min(lest,4);
        }
        //当没有新顾客加入之后，只需要让现有的顾客都游玩，然后保存结果
        while(lest>0){
            sum+=min(lest,4)*boardingCost-runningCost;
            if(sum>maxn){
                maxn=sum;
                ans=++i;
            }
            lest-=min(lest,4);
        }
        return ans;
    }
};
int main()
{
    Solution sl;
    vector<int> customers={10,10,1,0,0};
    cout<<sl.minOperationsMaxProfit(customers,4,4);
}