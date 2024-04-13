class Solution {
public:
    int minSteps(string s, string t) {
        
        int ans = 0 ;
        unordered_map<int,int> f1 ;
        
        for ( auto it : s )
            f1[it]++ ;
        
        for( auto it : t )
            f1[it]-- ;
         
        
        
        for ( auto it : f1 )
        {
            if ( it.second > 0 )
                ans += it.second ;
            
        }
        return ans ;
    }
};