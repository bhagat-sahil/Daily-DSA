class Solution {
public:
    int minimumRecolors(string bl, int k) {
        int count = 0 ; 
        
        for ( int i = 0 ; i < k ; i++ )
        {
            if ( bl[i] == 'W' )
                count++ ;
        }
        
        int ans = count ;
            
        for ( int i = 1 ; i <= bl.size()-k ; i++ )
        {
            if ( bl[i-1] == 'W' )
                count-- ;
            if ( bl[i+k-1] == 'W' )
                count++ ;
            
            ans = min ( ans, count ) ;
        }
        return ans ;
    }
};