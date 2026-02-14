class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size() ;
        map<int, int>mp ;
        for(int i = 0 ; i < n ; i ++){
            mp[a[i]] ++ ;
        }
        int j = 0 ;
        for(auto [k, v] : mp){
            a[j] = k ;
            j ++ ;
        }
        return j ;
    }
};