class Solution {
public:
    
    bool palin( int l, int r, string &s )
    {
        while ( l < r )
        {
            if ( s[l] != s[r] )
                return false ;
            
            l++ ;
            r-- ;
        }
        return true ;
    }
    
    
    bool validPalindrome(string s) {
        
        int l = 0, r = s.size()-1 ;
        
        while ( l < r )
        {
            if ( s[l] == s[r] )
            {
                l++ ;
                r-- ;
            }
            
            else 
                return palin( l+1, r, s ) || palin( l, r-1, s ) ;
            
        }
        return true ;
    }
};