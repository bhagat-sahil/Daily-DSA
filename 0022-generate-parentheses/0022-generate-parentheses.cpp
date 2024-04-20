class Solution {
public:
    
    bool isValid ( string temp )
    {
        int count = 0 ;
        
        for ( auto ch : temp )
        {
            if ( ch == '(' )
                count++ ;
            
            else count-- ;
            
            if ( count < 0 )
                return false ;
        }
        
        return count == 0 ;
    }
    
    
    void makeParenthesis ( string&temp, vector<string>&ans, int n )
    {
        if ( temp.size() == 2*n )
        {
            if ( isValid(temp) )
                ans.push_back(temp) ;
            return ;
        }
        
        temp.push_back('(') ;
        makeParenthesis ( temp, ans, n ) ;
        temp.pop_back() ;
        
        temp.push_back(')') ;
        makeParenthesis( temp, ans, n ) ;
        temp.pop_back() ;
    }
    
    
    vector<string> generateParenthesis(int n) {
        string temp ;
        vector<string>ans ;
        
        makeParenthesis( temp, ans, n ) ;
        return ans ;
        
    }
};