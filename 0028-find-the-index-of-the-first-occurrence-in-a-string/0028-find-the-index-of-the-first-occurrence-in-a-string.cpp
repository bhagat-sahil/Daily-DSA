class Solution {
public:
    int strStr(string h, string n) {
        
        if ( h == n )
            return 0 ;
        
        int b = h.size() ;
        int a = n.size() ;
        
        for ( int i = 0 ; i < b-a+1 ; i++ )
        {
            string s = h.substr(i,a) ;
            if ( s == n )
                return i ;
        }
        return -1 ;
    }
};