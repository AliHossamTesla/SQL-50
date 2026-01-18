class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& e, string a, string b) {
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i ++) cnt += (a[i] != b[i]) ;
        if(cnt & 1) return {-1} ;
        vector<vector<array<int, 2>>>g(n) ;
        for(int i = 0 ; i < e.size() ; i ++){
            int u = e[i][0], v = e[i][1] ;
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
        vector<int>ans;
        function<void(int, int, int)> dfs = [&](int v, int p, int e){
            for(auto [u, i] : g[v]){
                if(u == p) continue ;
                dfs(u, v, i) ;
            }
            if(a[v] != b[v] && e != -1){
                ans.push_back(e) ;
                a[v] = (1 - (a[v] - '0')) + '0' ;
                a[p] = (1 - (a[p] - '0')) + '0' ;
            }
        };
        dfs(0, -1, -1) ;
        sort(begin(ans), end(ans)) ;
        return ans ;
    }
};