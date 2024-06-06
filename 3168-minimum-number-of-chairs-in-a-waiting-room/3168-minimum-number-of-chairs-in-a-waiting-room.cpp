class Solution {
public:
    int minimumChairs(string s) {
        int chair = 0 ;
        int ans = 0 ;
        int People = 0 ;
        for ( auto &ch : s )
        {
            if ( ch == 'E' && chair <= People  )
            {
                ans++ ;
                chair++ ;
                People++ ;
            }
            else if ( ch == 'L' && People > 0 )
                People-- ;
            
            else 
                People++ ;
        }
        return ans ;
    }
};