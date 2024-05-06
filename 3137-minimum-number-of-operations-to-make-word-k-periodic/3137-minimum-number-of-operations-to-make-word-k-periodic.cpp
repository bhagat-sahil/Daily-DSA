class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> mp ;
        string s = "" ;
        int mx = INT_MIN ;
        
        for ( int i = 0 ; i < word.size() ; i++ )
        {
            s += word[i] ;
            if ( s.size() == k )
            {
                mp[s]++ ;
                mx = max( mx, mp[s] ) ;
                s = "" ;
            }
        }
        
        return word.size()/k - mx ;
    }
};