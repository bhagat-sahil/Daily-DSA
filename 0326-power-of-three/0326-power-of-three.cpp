class Solution {
public:
    
    bool findAns( long long p, long long n )
    {
        if ( p == n )   
            return true ;
        
        if ( p > n )
            return false ;
        
        return findAns( p*3, n ) ;
    }
    
    
    bool isPowerOfThree(int n) {
        if ( n == 1 )
            return true ;
        return findAns( 3, n ) ;
    }
};