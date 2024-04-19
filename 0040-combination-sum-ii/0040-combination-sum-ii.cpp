class Solution {
public:
    
    void findCombo ( int i, vector<vector<int>>&ans, vector<int>&temp, int target, vector<int>& c )
    {
        if ( target == 0 )
        {
            ans.push_back(temp) ;
            return ;
            
        }
        
        
        if ( target < 0 || i >= c.size() )
            return ;
        
        for ( int idx = i ; idx < c.size() ; idx++ )
        {
            if ( idx > i && c[idx] == c[idx-1] ) 
                continue ;
            
            temp.push_back(c[idx]) ;
            findCombo( idx+1, ans, temp, target-c[idx], c ) ;
            temp.pop_back() ;
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        
        vector<vector<int>> ans ; 
        vector<int> temp ;
        sort( c.begin(), c.end() ) ;
        
        findCombo( 0, ans, temp, target, c ) ;
        
        return ans ;
    }
};