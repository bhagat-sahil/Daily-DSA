class Solution {
public:
    

    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n = nums.size() ;
        
        
        vector<int> dp(n, 0) ;
        dp = nums ;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq ;
        
        pq.push( {dp[0], 0} ) ;
        
        int res = dp[0] ;
        
        for( int i = 1 ; i < n ; i++ )
        {
            
            while( !pq.empty() && pq.top().second < i - k ) 
                pq.pop();
                
            
            dp[i] = max( dp[i], nums[i] + pq.top().first ) ;
            
            pq.push( {dp[i], i} ) ;
            
            res = max( res, dp[i] ) ;
        }
        return res ;
    }
};