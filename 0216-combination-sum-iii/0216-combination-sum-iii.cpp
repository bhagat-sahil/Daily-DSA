class Solution {
public:
    
    
    void findCombo( int num, int k, int n, vector<int>&temp, vector<vector<int>>&ans )
    {
        if ( k == 0 && n == 0 )
        {
            ans.push_back(temp) ;
            return ;
        }
        
        if ( n < 0 || k == 0 || num > n || num > 9 )
            return ;
        
        temp.push_back(num) ;
        findCombo( num+1, k-1, n-num, temp, ans ) ;
        temp.pop_back() ;
        
        findCombo( num+1, k, n, temp, ans ) ;
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans ;
        vector<int> temp ;
            
        findCombo ( 1, k, n, temp, ans ) ;
        return ans ;
    }
};