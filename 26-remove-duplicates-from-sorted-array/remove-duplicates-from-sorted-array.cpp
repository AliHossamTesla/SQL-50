class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size(), i = 0, j = 0 ;
        while(i < n){
            if(i > 0 && a[i] == a[i - 1]) i ++ ;
            else{
                a[j] = a[i] ;
                i ++ ; j ++ ;
            }
        }
        return j ;
    }
};