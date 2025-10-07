class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0 ;
        for(int i : nums) g = gcd(i, g) ;
        return g == 1 ;
    }
};