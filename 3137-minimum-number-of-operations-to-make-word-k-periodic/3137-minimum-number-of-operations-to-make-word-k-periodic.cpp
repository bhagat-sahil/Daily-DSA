class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size() ;
        unordered_map<string,int> mp ;
        string s = "" ;
        int mx = INT_MIN ;
        int size = 0 ;
        for ( int i = 0 ; i < n ; i++ )
        {
            s += word[i] ;
            size++ ;
            if ( size == k )
            {
                mp[s]++ ;
                mx = max( mx, mp[s] ) ;
                s = "" ;
                size = 0 ;
            }
        }
        
        return n/k - mx ;
    }
};