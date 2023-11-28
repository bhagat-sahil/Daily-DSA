class Solution {
public:
    
    
    bool findAns( vector<int>&nums, int target, int index, vector<vector<int>>&dp )
    {
        if ( target == 0 )  return true ;
        
        if ( index >= nums.size() || target < 0 )   return false ;
        
        if ( dp[index][target] != -1 )
        {
                bool currentAns = (dp[index][target] == 1) ? true : false;
                return currentAns;
                
        }
        
        bool take = findAns( nums, target - nums[index], index + 1, dp ) ;
        bool NOTtake = findAns ( nums, target, index + 1, dp ) ;
        
        bool ans = take || NOTtake;
        return dp[index][target] = (ans == true) ? 1 : 0 ;
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        
        
        int totalSum = 0 ;
        for ( auto val : nums )     totalSum += val ;
        
        vector<vector<int>>dp(n+1,vector<int>(totalSum/2+1,-1)) ;
        
        if ( totalSum %2 != 0 ) return false ;
        else    return findAns( nums, totalSum/2, 0, dp ) ;
    }
};