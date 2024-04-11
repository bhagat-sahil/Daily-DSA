class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if ( s.size() != t.size() ) 
            return false ;
        unordered_map<int,int> countS ;
        unordered_map<int,int> countT ;

        for ( auto it : s ) 
            countS[it]++ ;
        
        for ( auto it : t ) 
            countT[it]++ ;
        
        for ( auto it : s )
        {
            if ( countS[it] != countT[it] )
                return false ;
        }
        
        return true ;
        
    }
};