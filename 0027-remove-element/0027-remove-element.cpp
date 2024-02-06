class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = size(nums) ;
        vector<int>temp ;
        int count = 0 ;
        for ( int i = 0 ; i < size(nums) ; i++ )
        {
            if ( val != nums[i] ) 
            {
                temp.push_back(nums[i]) ;
                count++ ;
            }
            
        }
        nums = temp ; 
        
        return count ;
    }
};