class Solution {
public:
    
    int findAtmost( vector<int>&s, int k )
    {
        int r = 0, l = 0, ans = 0 ;
        
        unordered_map<int,int>mp ;
        
        while ( r < s.size() )
        {
            mp[s[r]]++ ;
            
            if( mp.size() > k )
            {
                while( mp.size() > k )
                {
                    mp[s[l]]-- ;
                    if ( mp[s[l]] == 0 ) 
                        mp.erase(s[l]) ;
                    l++ ;
                }
            }
            ans += r - l + 1 ;
            r++ ;
            
        }
        return ans ;
    }
    int subarraysWithKDistinct(vector<int>& s, int k) {
        
        return findAtmost(s, k) - findAtmost(s,k-1) ;
        
    }
};