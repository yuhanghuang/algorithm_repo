/*
你正在参加一场比赛，给你两个 正 整数 initialEnergy 和 initialExperience 分别表示你的初始精力和初始经验。
另给你两个下标从 0 开始的整数数组 energy 和 experience，长度均为 n 。
你将会 依次 对上 n 个对手。第 i 个对手的精力和经验分别用 energy[i] 和 experience[i] 表示。当你对上对手时，需要在经验和精力上都 严格 超过对手才能击败他们，然后在可能的情况下继续对上下一个对手。
击败第 i 个对手会使你的经验 增加 experience[i]，但会将你的精力 减少  energy[i] 。
在开始比赛前，你可以训练几个小时。每训练一个小时，你可以选择将增加经验增加 1 或者 将精力增加 1 。
返回击败全部 n 个对手需要训练的 最少 小时数目。
https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/
*/ 
#include <iostream>  
#include <vector>
using namespace std;
// class Solution {
// public:
//     int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
//         int energycount = 0;
//         int experiencecount = 0;
//         int temp=0;
//         for(int i=0;i<energy.size();i++)
//         {
//             if(initialEnergy>energy[i] && initialExperience>experience[i])
//             {
//                 initialEnergy=initialEnergy-energy[i];
//                 initialExperience=initialExperience+experience[i];
//             }
//             else if(initialEnergy>energy[i] && initialExperience<=experience[i])
//             {
//                 temp=experience[i]-initialExperience+1;
//                 experiencecount+=temp;
//                 initialExperience=experience[i]+1;
//                 initialEnergy=initialEnergy-energy[i];
//                 initialExperience=initialExperience+experience[i];
//             }
//             else if(initialEnergy<=energy[i] && initialExperience>experience[i])
//             {
//                 temp=energy[i]-initialEnergy+1;
//                 energycount+=temp;
//                 initialEnergy=energy[i]+1;
//                 initialEnergy=initialEnergy-energy[i];
//                 initialExperience=initialExperience+experience[i];
//             }
//             else
//             {
//                 energycount+=energy[i]-initialEnergy+1;
//                 experiencecount+=experience[i]-initialExperience+1;
//                 initialEnergy+=energy[i]-initialEnergy+1;
//                 initialExperience+=experience[i]-initialExperience+1;
//                 initialEnergy=initialEnergy-energy[i];
//                 initialExperience=initialExperience+experience[i];
//             }
//         }
//         return energycount+experiencecount;
//     }
// };

//方法二

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum = 0;
        for (int e : energy) {
            sum += e;
        }
        int trainingHours = initialEnergy > sum ? 0 : sum + 1 - initialEnergy;
        for (int e : experience) {
            if (initialExperience <= e) {
                trainingHours += 1 + (e - initialExperience);
                initialExperience = 2 * e + 1;// 1 + (e - initialExperience)+initialExperience+e=2*e+1
            } else {
                initialExperience += e;
            }
        }
        return trainingHours;
    }
};


int main()
{
    Solution sl;
    int initialEnergy = 5, initialExperience = 3;
    vector<int> energy={1,4,3,2},experience={2,6,3,1};
    cout<<sl.minNumberOfHours(initialEnergy,initialExperience,energy,experience);
}