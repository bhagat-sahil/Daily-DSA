class Solution {
public:
    
    
    int findMaxLoot( int i, vector<int>&dp, vector<int>&nums, bool flag )
    {
        if ( i >= nums.size()) return 0 ;
        if ( i >= nums.size()-1 && flag ) return 0 ;
        
        if ( dp[i] != -1 ) return dp[i] ;
        
        int op1 = nums[i] + findMaxLoot( i+2, dp, nums, flag ) ;
        int op2 = findMaxLoot( i+1, dp, nums, flag ) ;
        
        return dp[i] = max( op1, op2 ) ;
        
    }
    
    
    
    int rob(vector<int>& nums) 
    {
        int n = nums.size() ;
        if ( n == 1 ) return nums[0] ;
        vector<int>dp(n+1,-1) ;
        
        int a = findMaxLoot(0,dp,nums,true) ;
        dp.assign(n + 1, -1);
        int b = findMaxLoot(1,dp,nums,false) ;
        return max(a,b) ;
        
    }
};