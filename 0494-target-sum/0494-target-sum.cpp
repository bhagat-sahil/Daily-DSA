class Solution {
public:
    
    
    int findWays( int i, vector<int>&nums, int target, unordered_map<string,int>&dp )
    {
        if ( target == 0 && i == nums.size() )  return 1 ;
        if ( i >= nums.size() ) return 0 ;
        
        string key = to_string(i) + "-" + to_string(target);
        
        if ( dp.find(key) != dp.end() ) return dp[key] ;
        
        int plus = findWays( i+1, nums, target - nums[i], dp ) ;
        int minus = findWays( i+1, nums, target + nums[i], dp ) ;
        
        return dp[key] = plus + minus ;
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>dp;
        return findWays( 0, nums, target, dp ) ;
    }
};