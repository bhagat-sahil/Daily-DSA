class Solution {
public:
    
    set<pair<int,int>>matrix ;
    int m, n ;
    
    
    Solution(int m, int n) {
        this->m = m ;
        this->n = n ;
    }
    
    vector<int> flip() {
        
        int row = rand() % m ;
        int col = rand() % n ;
        
        if ( matrix.find({row,col}) != matrix.end())     return flip() ;
            
        else{
            matrix.insert({row,col}) ;
            return {row, col} ;
        }
            
    }
    
    void reset() {
        matrix.clear() ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */