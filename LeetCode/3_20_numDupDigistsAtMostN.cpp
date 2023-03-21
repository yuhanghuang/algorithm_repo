#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<string.h>
using namespace std;
// class Solution {
// public:
//     vector<vector<int>> dp;

//     int f(int mask, const string &sn, int i, bool same) {
//         if (i == sn.size()) {
//             return 1;
//         }
//         if (!same && dp[i][mask] >= 0) {
//             return dp[i][mask];
//         }
//         int res = 0, t = same ? (sn[i] - '0') : 9;
//         for (int k = 0; k <= t; k++) {
//             if (mask & (1 << k)) {
//                 continue;
//             }
//             res += f(mask == 0 && k == 0 ? mask : mask | (1 << k), sn, i + 1, same && k == t);
//         }
//         if (!same) {
//             dp[i][mask] = res;
//         }
//         return res;
//     }

//     int numDupDigitsAtMostN(int n) {
//         string sn = to_string(n);
//         dp.resize(sn.size(), vector<int>(1 << 10, -1));
//         return n + 1 - f(0, sn, 0, true);
//     }
// };

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp)); // -1 表示没有计算过
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m)
                return is_num; // is_num 为 true 表示得到了一个合法数字
            if (!is_limit && is_num && dp[i][mask] != -1)
                return dp[i][mask];
            int res = 0;
            if (!is_num) // 可以跳过当前数位
                res = f(i + 1, mask, false, false);
            int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
                if ((mask >> d & 1) == 0) // d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            if (!is_limit && is_num)
                dp[i][mask] = res;
            return res;
        };
        return n - f(0, 0, true, false);
    }
};

int main()
{
    int n=20;
    Solution sl;
    cout<<sl.numDupDigitsAtMostN(n);
}
/*
class Solution {
    int[][] memo;   // memo[i][mask]记录当前选择顺位为i，已选状态为mask时，构造第i位及后面位的合法方案数
    char[] s;

    public int countSpecialNumbers(int n) {
        /*
        参考灵神の数位DP记忆化DFS模板：
        注意这题与LC1012是一样的，不过这题更直接求每一位都不相同数字
        dfs(i, mask, isLimit, hasNum) 代表从左到右选到第i个数字时(i从0开始)，前面数字已选状态为mask时的合法方案数
        各个参数的含义如下:
        i:当前选择的数字位次，从0开始
        mask:前面已择数字的状态，是一个10位的二进制数，如:0000000010就代表前面已经选了1
        isLimit:boolean类型，代表当前位选择是否被前面位的选择限制了；
            如n=1234，前面选了12，选第3位的时候会被限制在0~3，isLimit=true；否则是0~9，isLimit=false
        hasNum:表示前面是否已经选择了数字，若选择了就为true(识别直接构造低位的情况)
        时间复杂度:O(1024*M*10) 空间复杂度:O(1024*M)
        记忆化DFS的时间复杂度=状态数*每一次枚举的情况数
         
        s = String.valueOf(n).toCharArray();    // 转化为字符数组形式
        int m = s.length;
        memo = new int[m][1 << 10];     // i∈[0,m-1]，mask为一个10位二进制数
        // 初始化memo为-1代表该顺位下该已选状态还没进行计算
        for (int i = 0; i < m; i++) {
            Arrays.fill(memo[i], -1);
        }
        // 注意一开始最高位是有限制的，isLimit=true
        return dfs(0, 0, true, false);
    }

    // dfs(i, mask, isLimit, hasNum) 代表从左到右选第i个数字时，前面已选状态为mask时的合法方案数
    private int dfs(int i, int mask, boolean isLimit, boolean hasNum) {
        // base case
        // i越过最后一位，此时前面选了就算一个，没选的就不算，因为不选后面也没得选了
        if (i == s.length) return hasNum ? 1 : 0;
        // 已经计算过该状态，并且该状态是有效的，直接返回该状态
        // 这一步是降低时间复杂度的关键，使得记忆化dfs的时间复杂度控制得很低
        // !isLimit表示没有被限制的才可以直接得出结果，否则还要根据后面的数字进行计算子问题计算
        if (!isLimit && hasNum && memo[i][mask] != -1) return memo[i][mask];
        int res = 0;    // 结果
        // 本位可以取0(可直接构造低位数)的情况，此时要加上构造低位数0xxx的方案数
        // 将是否选了数字作为分类条件是为了避免出现00010这样有多个0的就不能统计了
        if (!hasNum) res = dfs(i + 1, mask, false, false);
        // 构造与当前顺位相同位数的数字就要枚举可选的数字进行DFS
        // 枚举的起点要视hasNum而定，如果前面选择了数字，那么现在可以选0；否则只能从1开始
        // 枚举得终点视isLimit而定，若被限制了只能到s[i]，否则可以到9
        for (int k = hasNum ? 0 : 1, end = isLimit ? s[i] - '0' : 9; k <= end; k++) {
            // 如果该数字k还没有被选中，那猫就可以选该位数字
            if (((mask >> k) & 1) == 0) {
                // 方案数遵循加法原理
                // i:进行下一位的DFS，因此为i+1
                // mask:由于该位选中了k，mask掩膜传下去就要更新，已选状态加上k
                // isLimit:当且仅当前面的被限制了且该位被限制
                // hasNum:该位选了必定为true
                res += dfs(i + 1, mask | (1 << k), isLimit && k == end, true);
            }
        }
        if (!isLimit && hasNum) memo[i][mask] = res;    // 如果前面没有限制，表明后面都是同质的，可以记录进memo中
        return res;
    }
}
*/

/*
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        auto s = to_string(n);
        int m = s.length(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp)); // -1 表示没有计算过
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m)
                return is_num; // is_num 为 true 表示得到了一个合法数字
            if (!is_limit && is_num && dp[i][mask] != -1)
                return dp[i][mask];
            int res = 0;
            if (!is_num) // 可以跳过当前数位
                res = f(i + 1, mask, false, false);
            int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
                if ((mask >> d & 1) == 0) // d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            if (!is_limit && is_num)
                dp[i][mask] = res;
            return res;
        };
        return n - f(0, 0, true, false);
    }
};

链接：https://leetcode.cn/problems/numbers-with-repeated-digits/solution/by-endlesscheng-c5vg/

*/