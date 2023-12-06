class Solution {
public:
    
    int findCoinChange( int i, vector<int>&coins, int amount, vector<vector<int>>&dp )
    {
        if ( amount == 0 ) return 1 ;
        if ( i == coins.size()) return 0 ;
        
        if ( dp[i][amount] != -1 )  return dp[i][amount] ;
        int take = 0 ;
        if ( coins[i] <= amount )
            take = findCoinChange( i, coins, amount-coins[i], dp) ;
        int notTake = findCoinChange( i+1, coins, amount, dp ) ;
        
        return dp[i][amount] = take+notTake ;
    }
    
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp( coins.size()+1, vector<int>(5001, -1)) ;
        int ans = findCoinChange( 0, coins, amount, dp ) ;
        return ans ;
    }
};