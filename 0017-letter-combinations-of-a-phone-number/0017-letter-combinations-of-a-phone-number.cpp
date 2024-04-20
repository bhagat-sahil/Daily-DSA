class Solution {
public:
    
    void findCombo ( int curIdx, unordered_map<char,string>&mp, string &temp,
                   vector<string>&ans, string digits )
    {
        if ( curIdx >= digits.size() )
        {
            ans.push_back(temp) ;
            return ;
        }
        
        char ch = digits[curIdx] ;
        string s = mp[ch] ;
        
        for ( int i = 0 ; i < s.size() ; i++ )
        {
            temp.push_back(s[i]) ;
            findCombo( curIdx+1, mp, temp, ans, digits ) ;
            temp.pop_back() ;
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans ;
        string temp = "" ;
        if ( digits == "" )
            return ans ;
        
        unordered_map<char,string> mp ;
        
        mp.insert({'2',"abc"}) ;
        mp.insert({'3',"def"}) ;
        mp.insert({'4',"ghi"}) ;
        mp.insert({'5',"jkl"}) ;
        mp.insert({'6',"mno"}) ;
        mp.insert({'7',"pqrs"}) ;
        mp.insert({'8',"tuv"}) ;
        mp.insert({'9',"wxyz"}) ;
        
        findCombo( 0, mp, temp, ans, digits ) ;
        return ans ;
         
    }
};