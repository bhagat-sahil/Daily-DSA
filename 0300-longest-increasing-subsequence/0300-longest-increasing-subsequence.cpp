class Solution {
public:
    
    
//     int findLength( int i , vector<int>&nums, int prev_i, vector<vector<int>>&dp )
//     {
//         if ( i == nums.size())  return 0 ;
        
        
//         if ( dp[i][prev_i+1] != -1 ) return dp[i][prev_i+1] ;
        
//         int take = 0 ; 
//         if ( prev_i == -1 || nums[prev_i] < nums[i])
//         {
//             take = 1 + findLength( i+1, nums, i, dp ) ;
//         }
        
//         int notTake = findLength( i+1, nums, prev_i, dp ) ;
        
        
//         return dp[i][prev_i+1] = max( take, notTake ) ;
//     }
    
    
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size() ;
        vector<int>next(n+1,0), curr(n+1,0) ;
        
        for ( int i = n-1 ; i >= 0 ; i-- )
        {
            for ( int prev = i-1 ; prev >= -1 ; prev-- )
            {
                
                int take = 0 , notTake = next[prev+1] ;
                if ( prev == -1 || nums[prev] < nums[i])
                {
                    take = 1 + next[i+1] ;
                }
                curr[prev+1] = max( take, notTake ) ;
            }
            next = curr ;
        }
        return next[0] ;
    }
};
























