class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp ;
        int ans = 0 ;
        bool check = false ;
        
        for ( int i = 0 ; i < s.size() ; i++ )
        {
            if ( mp.find(s[i]) != mp.end() )
            {
                check = true ;
                ans = max( ans, i - mp[s[i]] ) ;
            }
            else 
            {
                mp[s[i]] = i+1 ;
            }
        }
        return ( check ) ? ans : -1 ;
        
    }
};