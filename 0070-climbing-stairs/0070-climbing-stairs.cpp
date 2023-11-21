class Solution {
public:

    //  SPACE OPTIMISATION
    //
    int climbStairs(int n) 
    {
        int prev = 1 ;
        int prev2 = 1 ;
        int curr ;
        
        for ( int i = 2 ; i <= n ; i++ )
        {
            curr = prev + prev2 ;
            prev2 = prev ;
            prev = curr ;
        }
     
        return prev ;
    }
};