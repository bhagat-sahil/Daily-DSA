class Solution {
public:
    
    bool isVowel ( char ch )
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ;
    }
    
    int maxVowels(string s, int k) {
        int cnt = 0 ;
        for ( int i = 0 ; i < k ; i++ )
        {
            if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||s[i] == 'o' || s[i] == 'u' )
                cnt++ ;
        }
        int ans = cnt ;
        
        for ( int i = 1 ; i <= s.size()-k ; i++ )
        {
            if ( isVowel(s[i-1]) )
                cnt-- ;
            if ( isVowel(s[i+k-1]) )
                cnt++ ;
            ans = max ( ans, cnt ) ;
        }
        return ans ;
    }
};