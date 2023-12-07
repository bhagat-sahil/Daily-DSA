class Solution {
public:
    
    int MaxProfit( int i, int buy, int transac, vector<int>&prices, vector<vector<vector<int>>>&dp )
    {
        if ( transac == 2 ) return 0 ;
        if( i > prices.size()-1 )  return 0 ;
        
        
        if ( dp[i][buy][transac] != 100001 ) return dp[i][buy][transac] ; 
        int take = 0 ;
        if ( buy == 0 )
        take = -prices[i] + MaxProfit( i+1, 1, transac, prices, dp ) ;
        if ( buy == 1 )
        take = prices[i] + MaxProfit( i+1, 0, transac+1, prices, dp ) ;
        int ignore = MaxProfit( i+1, buy, transac, prices, dp ) ;
        
        return dp[i][buy][transac] = max(take,ignore) ;
        
    }

    int maxProfit(vector<int>& prices) 
    {
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(3,vector<int>(3,100001))) ;
        return MaxProfit( 0, 0, 0, prices, dp ) ;
    }
};