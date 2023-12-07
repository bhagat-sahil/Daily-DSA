class Solution {
public:
    
    int MaxProfit( int i, int buy, vector<int>&prices, vector<vector<int>>&dp )
    {
        if( i > prices.size()-1 )  return 0 ;
        
        
        if ( dp[i][buy] != 10001 ) return dp[i][buy] ; 
        int take = 0 ;
        if ( buy == 0 )
        take = -prices[i] + MaxProfit( i+1, 1, prices, dp ) ;
        if ( buy == 1 )
        take = prices[i] + MaxProfit( i+1, 0, prices, dp ) ;
        int ignore = MaxProfit( i+1, buy, prices, dp ) ;
        
        return dp[i][buy] = max(take,ignore) ;
        
    }

    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>>dp(prices.size(), vector<int>(3,10001)) ;
        return MaxProfit( 0, 0, prices, dp ) ;
    }
};