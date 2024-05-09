class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(), happiness.end(), greater<int>()) ;
        
        long long ans = 0 ;
        int count = 0 ;
        
        for ( int i = 0 ; i < k ; i++ )
        {
            if ( happiness[i] >= count )
                ans = ans + happiness[i] - count ;
            
            else return ans ;
            count++ ;
        }
        return ans ;
    }
};