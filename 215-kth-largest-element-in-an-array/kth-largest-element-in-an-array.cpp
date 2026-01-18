class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int SHIFT = 1e4 ;
        const int MAX_SIZE = 2*SHIFT + 5 ;
        int count[MAX_SIZE] = {};
        for(int i : nums){
            count[i + SHIFT] ++ ;
        }
        int current_kth = 0 ;
        for(int i = MAX_SIZE - 1 ; i >= 0 ; i --){
            current_kth += count[i] ;
            if(current_kth >= k) return i - SHIFT ;
        }
        assert(0) ;
        return -1 ;
    }
};