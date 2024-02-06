class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        if ( size(strs) == 0 ) 
            return {{""}} ;
        
        vector<vector<string>>ans ;
        unordered_map<string,vector<string>> s ;
        
        for ( auto &it : strs )
        {
            string temp = it ;
            sort(begin(temp),end(temp)) ;
            s[temp].push_back(it) ;
        }
        for ( auto &it : s )
        {
            auto temp = it.second ;
            ans.push_back(temp) ;
        }
        return ans ;
    }
};