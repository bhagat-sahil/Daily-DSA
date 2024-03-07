class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans = 0 ;
        int r = 0, l = 0 ;
        unordered_map<char,int>mp ;
        while ( r < s.size() )
        {
            if ( mp.find(s[r]) == mp.end() || mp[s[r]] < l )
            {
                mp[s[r]] = r ;
                ans = max( ans, r - l + 1 ) ;
            }
            else
            {
                l = mp[s[r]] + 1 ;
                // while ( mp[s[r]] != 0 )
                // {
                //     mp[s[l]]-- ;
                //     l++ ;
                // }
                mp[s[r]] = r ;
            }
            r++ ;
        }
        return ans ;
    }
};