class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end()) ;
        
        string ans = "" ;
        string a = strs[0] ;
        string b = strs[strs.size()-1] ;
        
        
        int i = 0, j = 0 ;
        
        while ( i < a.size() && j < b.size() )
        {
            if ( a[i] == b[j] )
                ans += a[i] ;
            else 
                break ;
            i++ ;
            j++ ;
        }
        return ans ; 
        
    }
};