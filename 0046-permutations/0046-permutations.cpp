class Solution {
public:
    
    void findCombo ( set<int>&s , vector<vector<int>>&ans, vector<int>&temp, vector<int>&nums )
    {
        if ( temp.size() == nums.size() )
        {
            ans.push_back(temp) ;
            return ;
        }
        
        for ( int i = 0 ; i < nums.size() ; i++ )
        {
            if ( s.find(nums[i]) == s.end() )
            {
                temp.push_back(nums[i]) ;
                s.insert(nums[i]) ;
                
                findCombo( s, ans, temp, nums ) ;
                
                temp.pop_back() ;
                s.erase(nums[i]) ;
                
            }
        }
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int>temp ;
        set<int> s ;
        
        findCombo( s, ans, temp, nums ) ;
        return ans ;
    }
};