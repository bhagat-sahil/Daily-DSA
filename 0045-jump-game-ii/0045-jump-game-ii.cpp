class Solution {
public:
    
    int create(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx == nums.size() -1) return 0;
        if ( nums[idx] == 0 )  return 1e9 ;
        
        if(dp[idx] != -1) return dp[idx];
        int reach = idx + nums[idx];
        int ans = INT_MAX ;
        for(int jump=idx + 1; jump <= reach; jump++) {
            if(jump < nums.size())
            {
                int temp = (long long)1+create(nums, jump, dp) ;
                ans = min( ans, temp) ;
            }
        }
        return dp[idx] = ans ;
    }
    
    
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1) ;
        return create( nums, 0, dp ) ;
    }
};