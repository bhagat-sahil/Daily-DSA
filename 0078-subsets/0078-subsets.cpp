class Solution {
public:
    
    
    void findSubsets( int idx, vector<int>& nums, vector<vector<int>>&ans, vector<int>&temp )
    {
        if ( idx >= nums.size() )
            return ;
        
        temp.push_back(nums[idx]) ;
        
        ans.push_back(temp) ;
        
        findSubsets( idx+1, nums, ans, temp ) ;
        
        temp.pop_back() ;
        
        findSubsets( idx+1, nums, ans, temp ) ;
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans ;
        vector<int>temp ;
        ans.push_back(temp) ;
        
        
        findSubsets( 0, nums, ans, temp ) ;
        return ans ;
    }
};