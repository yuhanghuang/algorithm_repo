class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>> vec1(1000,vector<int>(3,1));

        vector<vector<int>> vec2(pairs.size(),vector<int>(2,0));
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();

        for(int i=0;i<pairs.size()-1;i++){
            vec1[i].push_back(i);
            vec1[i].push_back(pairs[i][1]);
            for(int j=i+1;j<pairs.size();j++)
            {
                if(pairs[j][0]>vec1[i][1])
                {
                    vec1[i][2]+=1;
                    vec1[i][1]=pairs[j][1];
                }
                
            }
        }
        int max=0;
        for(int s=0;s<vec1.size();s++){
            if(vec1[s][2]>=max)
            {
                max=vec1[s][2];
            }
        }
        // return max;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};




