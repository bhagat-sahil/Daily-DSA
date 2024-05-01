class Solution {
public:
    
    string findAns ( string &word, int r )
    {
        if ( r == word.size() )
            return word ;
        
        int l = 0 ;
        
        while ( l < r )
        {
            swap( word[l], word[r] ) ;
            r-- ;
            l++ ;
        }
        return word ;
    }
    string reversePrefix(string word, char ch) {
        int l = 0 , r ;
        
        for ( r = 0 ; r < word.size() ; r++ )
        {
            if ( ch == word[r] )
                break ;
        }
        
        return findAns ( word, r ) ;
    }
};