class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size() ;
        int l = 0, r = n - 1 ;
        while(l < r){
            int sum = a[l] + a[r] ;
            if(sum == target) return {l + 1, r + 1} ;
            if(sum > target) r -- ;
            else l ++ ;
        }
        return {-1, -1} ;
    }
};