class Solution {
public:
    int lengthOfLastWord(string s) {
        bool check = false ;
        
        int len = 0 ;
        for ( int i = s.size()-1 ; i >= 0 ; i-- )
        {
            if ( s[i] != ' ' )
            {
                len++ ;
                check = true ;
            }
            
            else if ( check )
                return len ;
          
        }
        return len ;
    }
};