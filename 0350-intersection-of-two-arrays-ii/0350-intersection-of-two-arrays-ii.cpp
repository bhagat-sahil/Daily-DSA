class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1 ;
        vector<int>ans ;
        
        for ( int i = 0 ; i < size(nums1) ; i++ )
            m1[nums1[i]]++ ;
        
        for ( int i = 0 ; i < size(nums2) ; i++ )
        {
            if ( m1[nums2[i]] > 0 )
            {
                ans.push_back(nums2[i]) ;
                m1[nums2[i]]-- ;
            }
        }
        return ans ;
    }
};