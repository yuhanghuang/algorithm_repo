#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int shortestDistance(int n, vector<int> a, int x, int y) {
    vector<int> dp(n, 0);
    dp[x - 1] = a[x - 1];
    for (int i = x; i < y; ++i) {
        dp[i] = min(dp[i - 1] + a[i - 1], dp[x - 1] + a[i - 1]);
    }
    return dp[y - 1];
}

int main() {
    int n = 5;
    vector<int> a = {2, 3, 4, 5, 1};
    int x = 1;
    int y = 4;
    
    int result = shortestDistance(n, a, x, y);
    cout << "最短距离：" << result << endl;

    return 0;
}
