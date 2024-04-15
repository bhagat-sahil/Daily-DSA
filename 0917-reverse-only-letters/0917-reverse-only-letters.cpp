class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size()-1 ;
        
        while ( l < r )
        {
            if ( isalpha(s[l]) && isalpha(s[r]) )
            {
                swap( s[l], s[r] ) ;
                r-- ;
                l++ ;
            }
                
            
            else if ( isalpha(s[l]) )
                r-- ;
            else 
                l++ ;
        }
        return s ;
    }
};