class Solution {
public:
    bool isHappy(int n) {
        
//         if ( n == 1 || n == 7 ) 
//             return true ;
        
//         if ( n < 10 )
//             return false ;
        
        while ( n > 10 )
        {
            int temp = 0 ;
            string s = to_string ( n ) ;
            for ( auto it : s )
            {
                temp = temp + pow((it-'0'),2) ;
            }
            n = temp ;
        }
        return n == 1 || n == 7 || n == 10 ;
    }
};