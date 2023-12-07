class Solution {
public:
    
    int MaxProfit( int i, int buy, int transac, vector<int>&prices, vector<vector<vector<int>>>&dp, int k )
    {
        if ( transac == k ) return 0 ;
        if( i > prices.size()-1 )  return 0 ;
        
        
        if ( dp[i][buy][transac] != 1001 ) return dp[i][buy][transac] ; 
        int take = 0 ;
        if ( buy == 0 )
        take = -prices[i] + MaxProfit( i+1, 1, transac, prices, dp, k ) ;
        if ( buy == 1 )
        take = prices[i] + MaxProfit( i+1, 0, transac+1, prices, dp, k ) ;
        int ignore = MaxProfit( i+1, buy, transac, prices, dp, k ) ;
        
        return dp[i][buy][transac] = max(take,ignore) ;
        
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(3,vector<int>(k,1001))) ;
        return MaxProfit( 0, 0, 0, prices, dp, k ) ;
    }
};