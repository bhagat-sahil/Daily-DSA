class Solution {
public:
    
    int findMinCost( int curStairs, vector<int>&cost, vector<int>&dp )
    {
        if ( curStairs >= cost.size() )  return 0 ;
        
        if ( dp[curStairs] != -1 )  return dp[curStairs] ;
        int oneStep = findMinCost( curStairs + 1 , cost, dp ) + cost[curStairs] ;
        int twoStep = findMinCost( curStairs + 2, cost, dp ) + cost[curStairs] ;

        return dp[curStairs] = min(oneStep,twoStep) ;
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int>dp(cost.size() + 1, -1 ) ;
        return min(findMinCost( 0, cost, dp ), findMinCost(1, cost, dp )) ;
    }
};