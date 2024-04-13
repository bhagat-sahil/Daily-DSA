class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> f1 ;
        
        int ans = 0 ;
        
        for ( auto it : s )
            f1[it]++ ;
        
        for ( auto it : t )
            f1[it]-- ;
        
        
        for ( auto it : f1 )
            ans += abs(it.second) ;
        
        return ans ;
    }
};