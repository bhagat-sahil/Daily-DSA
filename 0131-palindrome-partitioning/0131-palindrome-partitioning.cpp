class Solution {
public:
    
    
    bool isPalindrome ( int s, int e, string &str )
    {
        while ( s < e )
        {
            if ( str[s] != str[e] )
                return false ;
            
            s++ ;
            e-- ;
        }
        return true ;
    }
    
    
    void makeSubstring ( int idx, string&s, vector<string>&temp, vector<vector<string>>&ans )
    {
        if ( idx == s.size() )
        {
            ans.push_back(temp) ;
            return ;
        }
        for ( int i = idx ; i < s.size() ; i++ )
        {
            if ( isPalindrome(idx,i,s) )
            {
                temp.push_back(s.substr(idx,i-idx+1)) ;
                makeSubstring ( i+1, s, temp, ans ) ;
                temp.pop_back() ;
                
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ;
        vector<string> temp ;
        
        makeSubstring( 0, s, temp, ans ) ;
        return ans ;
        
    }
};