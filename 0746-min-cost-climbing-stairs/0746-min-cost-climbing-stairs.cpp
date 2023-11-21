class Solution {
public:
  
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int>dp(cost.size() + 1, -1 ) ;
        int n = cost.size() ;
     
        for ( int i = 2 ; i < cost.size() ; i++ )
        {
            cost[i] = cost[i] + min( cost[i-1], cost[i-2] ) ;
        }
        return min( cost[n-2], cost[n-1] ) ;
    }
};