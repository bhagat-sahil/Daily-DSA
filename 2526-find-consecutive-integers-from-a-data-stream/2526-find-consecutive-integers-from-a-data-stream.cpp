class DataStream {
public:
    
    int k = 0 ;
    int value = 0 ;
    int count = 0 ;
    
    DataStream(int value, int k) {
        this->k = k ;
        this->value = value ;
    }
    
    bool consec(int num) {
      
        if ( value == num ) count++ ;
        else count = 0 ;
        
        return count >= k ;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */