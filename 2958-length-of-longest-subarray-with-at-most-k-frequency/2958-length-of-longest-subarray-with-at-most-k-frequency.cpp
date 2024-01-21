class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int n = size(nums) ;
        unordered_map<int,int>mp ;
        
        int i = 0 ; 
        int j = 0 ;
        int ans = 0 ;
        
        while( j < n )
        {
            mp[nums[j]]++ ;
            while( mp[nums[j]] > k )
            {
                mp[nums[i]]-- ;
                i++ ;
            }
            ans = max( ans, j - i ) ;
            j++ ;
        }
        return ans+1 ;
    }
};