class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp ;
        
        for ( auto it : magazine )
            mp[it]++ ;
        
        for ( auto it : ransomNote )
        {
            if ( mp.find(it) == mp.end() )
                return false ;
            else 
                mp[it]-- ;
        }
        
        for ( auto it : mp )
        {
            if ( it.second < 0 )
                return false ;
        }
        
        return true ;
    }
};