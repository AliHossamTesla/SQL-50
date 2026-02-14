class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size() ;
        for(int i = 0 ; i < n ; i ++){ // O(n^2)
            int lo = i + 1, hi = n - 1 ;
            while(lo <= hi){
                int mid = (lo + hi)/2 ;
                if(a[i] + a[mid] == target) return {i + 1, mid + 1};
                else if(a[i] + a[mid] > target) hi = mid - 1 ;
                else lo = mid + 1 ;
            }
            
        }
        return {-1, -1} ;
    }
};