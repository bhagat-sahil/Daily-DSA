class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans = 0 ;
        int r = 0, l = 0 ;
        unordered_map<char,int>mp ;
        while ( r < s.size() )
        {
            if ( mp.count(s[r]) == 0 )
            {
                mp[s[r]]++ ;
                ans = max( ans, r - l + 1 ) ;
            }
            else
            {
                while ( mp.count(s[r]) != 0 )
                {
                    mp[s[l]]-- ;
                    if ( mp[s[l]] == 0 )
                        mp.erase(s[l]) ;
                    l++ ;
                }
                mp[s[r]]++ ;
            }
            r++ ;
        }
        return ans ;
    }
};