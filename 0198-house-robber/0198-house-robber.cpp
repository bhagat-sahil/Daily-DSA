class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size() ;
        if( n == 1 ) return nums[0] ;
        //vector<int>dp(n+1,-1) ;
        
        int curr ;
        int prev2 = nums[0] ;
        int prev = max( nums[0], nums[1] ) ;
        
        for ( int i = 2 ; i < n ; i++ )
        {
            curr = max( prev, nums[i] + prev2 ) ;
            prev2 = prev ;
            prev = curr ;
        }
        return max(curr,prev) ;
    }
};