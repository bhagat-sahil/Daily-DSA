class Solution {
public:
    
    struct ComparePairs {
    bool operator()(const pair<float, pair<int, int>>& a, const pair<float, pair<int, int>>& b) const {
        return a.first > b.first; // 
    }
};
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans ;
        priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, ComparePairs> pq;
        
        for ( int i = 0 ; i < arr.size() ; i++ )
        {
            for ( int j = 0 ; j < arr.size() ; j++ )
            {
                if ( i != j )
                {
                    float x = (float)arr[i]/arr[j] ;
                    pq.push({x,{arr[i], arr[j]}}) ;
                }
            }
        }
        k-- ;
        // cout<<k<<endl ;
        while ( k-- )
        {
            // cout<<"hi"<<endl ;
            pq.pop() ;
        }
        pair<float, pair<int, int>> top_element = pq.top();
        ans.push_back(top_element.second.first) ;
        ans.push_back(top_element.second.second) ;
        return ans ;
    }
    
};