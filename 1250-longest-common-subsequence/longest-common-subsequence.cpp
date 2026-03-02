class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size() ;
        vector<int>dp(m + 1) ;
        for(int i = 1 ; i <= n ; i ++){
            vector<int>ndp(m + 1) ;
            for(int j = 1 ; j <= m ; j ++){
                if(s[i - 1] == t[j - 1]) ndp[j] = dp[j - 1] + 1 ;
                else ndp[j] = max(ndp[j - 1], dp[j]) ;
            }
            dp = ndp ;
        }
        return dp.back() ;
    }
};