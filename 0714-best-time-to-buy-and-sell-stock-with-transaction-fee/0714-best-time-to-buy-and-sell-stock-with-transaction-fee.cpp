class Solution {
public:
  
    int MaxProfit( int i, int buy, vector<int>&prices, vector<vector<int>>&dp, int fee )
    {
        
        if( i > prices.size()-1 )  return 0 ;
        
        
        if ( dp[i][buy] != 50001 ) return dp[i][buy] ; 
        int take = 0 ;
        if ( buy == 0 )
        take = -prices[i] + MaxProfit( i+1, 1, prices, dp, fee ) ;
        if ( buy == 1 )
        take = prices[i] + MaxProfit( i+1, 0, prices, dp, fee ) - fee ;
        int ignore = MaxProfit( i+1, buy, prices, dp, fee ) ;
        
        return dp[i][buy] = max(take,ignore) ;
        
    }

    int maxProfit(vector<int>& prices, int fee) 
    {
        vector<vector<int>>dp(prices.size(), vector<int>(3,50001)) ;
        return MaxProfit( 0, 0, prices, dp, fee ) ;
    }
};
    
