class Solution {
public:
    int popcount(int n){
        int count = 0 ;
        for(int bit = 0 ; bit < 20 ; bit ++){
            if(n & (1 << bit)){
                count ++ ;
            }
        }
        return count ;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n + 1, 0) ;
        for(int i = 0 ; i <= n ; i ++){
            ans[i] = popcount(i) ;
        }
        return ans ;
    }
};