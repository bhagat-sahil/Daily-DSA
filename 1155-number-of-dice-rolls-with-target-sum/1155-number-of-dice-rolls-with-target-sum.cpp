class Solution {
public:
    
    int totWays( int dice, int faces, int target, vector<vector<int>>&dp, int mod )
    {
        if ( target < 0 )  return 0 ;
        if ( dice == 0 && target != 0 ) return 0 ;
        if ( dice != 0 && target == 0 ) return 0 ;
        if ( dice == 0 && target == 0 )  return 1 ;
        
        
        
        if ( dp[dice][target] != -1 )    return dp[dice][target] ;
        long long ans = 0 ;
        for ( int i = 1 ; i <= faces ; i++ )
        {
            ans = (ans + totWays( dice-1, faces, target-i, dp, mod ))% mod ;
        }
        return dp[dice][target] = ans ;
        
    }
    

    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9+7 ;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1)) ;
        return totWays( n, k, target, dp, mod ) ; 
        
    }
};