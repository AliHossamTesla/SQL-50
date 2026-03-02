class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size() ;
        vector<vector<int>>dp(2, vector<int>(m + 1)) ;
        int cnt = 0 ;
        for(int i = 1; i <= n ; i ++, cnt ^= 1){
            for(int j = 1 ; j <= m ; j ++){
                if(s[i - 1] == t[j - 1]) dp[cnt][j] = dp[1 - cnt][j - 1] + 1 ;
                else dp[cnt][j] = max(dp[cnt][j - 1], dp[1 - cnt][j]) ;
            }
        }
        return dp[cnt^1].back() ;
    }
};