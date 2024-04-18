class Solution {
public:
    
    void findCombo( int i, vector<int>& c, int target, vector<vector<int>>&ans, vector<int>&temp )
    {
        if ( target == 0 )
        {
            ans.push_back(temp) ;
            return ;
        }
        if ( i >= c.size() || target < 0 )
            return ;
        
        temp.push_back(c[i]) ;
        findCombo( i, c, target-c[i], ans, temp ) ;
        
        temp.pop_back() ;
        
        findCombo( i+1, c, target, ans, temp ) ;
    
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>>ans ;
        vector<int>temp ;
        
        findCombo( 0, c, target, ans, temp ) ;
        
        return ans ;
    }
};