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
        vector<int>dp(n+1,1), hash(n+1,0) ;
        int maxi = 1 ;
        int lastIdx = 0 ;
        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int prev = 0 ; prev < i ; prev++ )
            {
                if ( nums[i] > nums[prev] && dp[i] < 1+ dp[prev] )
                {
                    dp[i] = 1+ dp[prev]  ;
                    hash[i] = prev ;
                }
            }
            if ( dp[i] > maxi )
            {
                maxi = dp[i] ;
                lastIdx = i ;
            }
        }
        vector<int>temp ;
        temp.push_back(nums[lastIdx]) ;
        while ( hash[lastIdx] != lastIdx )
        {
            lastIdx = hash[lastIdx] ;
            temp.push_back(nums[lastIdx]) ;
        }
        reverse( temp.begin(),temp.end()) ;
        return maxi ;
    }
};
























