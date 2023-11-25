class Solution {
public:
    
    int findMaxLoot( vector<int>&nums, int s, int end )
    {
        int n = nums.size() ;
        vector<int>dp(n+1, -1 ) ;
        dp[0] = nums[s] ;
        dp[1] = max( nums[s], nums[s+1] ) ;
        int i = s ;
        s = 2 ;
        while ( s < end - i + 1 )
        {
            if ( i == 1 )
            {
                dp[s] = max(dp[s-1], dp[s-2] + nums[s+1]) ;
            }
            else dp[s] = max(dp[s-1], dp[s-2] + nums[s]) ;
            s++ ;
        }
        return max(dp[n-1],dp[n-2]) ;
    
    }
    
    int rob(vector<int>& nums) 
    {
        if ( nums.size() == 1 ) return nums[0] ;
        if ( nums.size() == 2 ) return max(nums[0],nums[1]) ;
        return max(findMaxLoot( nums, 0, nums.size()-2 ), findMaxLoot( nums, 1, nums.size()-1 )) ;
        //return findMaxLoot( nums, 0, nums.size()-2 ) ;
        //return findMaxLoot( nums, 1, nums.size()-1 ) ;
    }
};