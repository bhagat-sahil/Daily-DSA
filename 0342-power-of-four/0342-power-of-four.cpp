class Solution {
public:
    
    bool findAns( long long p, long long n )
    {
        if ( p == n )   
            return true ;
        
        if ( p > n )
            return false ;
        
        return findAns( p*4, n ) ;
    }
    
    bool isPowerOfFour(int n) {
        if ( n == 1 )
            return true ;
        return findAns( 4, n ) ;
    }
};