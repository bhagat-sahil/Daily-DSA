class Solution {
public:
    
    void findAns( int idx, vector<int>& nums, set<vector<int>>&s, vector<int> temp )
    {
        if ( idx == nums.size())
        {
            sort(temp.begin(),temp.end()) ;
            s.insert(temp) ;
            return ;
        }
        
        findAns( idx+1, nums, s, temp ) ;
        
        temp.push_back(nums[idx]) ;
        
        findAns( idx+1, nums, s, temp ) ;
          
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans ;
        vector<int>temp ;
        
        set<vector<int>>s ;
        
        findAns( 0, nums, s, temp ) ;
        
        for ( auto it : s )
            ans.push_back(it) ;
        
        return ans ;
        
    }
};