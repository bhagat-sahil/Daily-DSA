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
        vector<int>dp(n+1,1) ;
        int maxi = 0 ;
        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int prev = 0 ; prev < i ; prev++ )
            {
                if ( nums[i] > nums[prev])
                {
                    dp[i] = max( dp[i], 1+ dp[prev] ) ;
                }
            }
            maxi = max( maxi, dp[i]) ;
        }
        return maxi ;
    }
};
























