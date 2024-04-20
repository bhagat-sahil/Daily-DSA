class Solution {
public:

    
    void makeParenthesis ( int close, int open, string&temp, vector<string>&ans, int n )
    {
        if ( temp.size() == 2*n && open == close )
        {
            ans.push_back(temp) ;
            return ;
        }
        
        if ( close < open )
        {
            temp.push_back(')') ;
            makeParenthesis( close+1, open, temp, ans, n ) ;
            temp.pop_back() ;
        }
        if ( open < n )
        {
            temp.push_back('(') ;
            makeParenthesis( close, open+1, temp, ans, n ) ;
            temp.pop_back() ;
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        string temp ;
        vector<string>ans ;
        
        makeParenthesis( 0, 0, temp, ans, n ) ;
        return ans ;
        
    }
};