class MyHashMap {
public:
    
    vector<int>ds ;
    
    MyHashMap() : ds( 1e6+1, -1 ) {
        
    }
    
    void put(int key, int value) {
        ds[key] = value ;
    }
    
    int get(int key) {
        return ds[key] ;
    }
    
    void remove(int key) {
        ds[key] = -1 ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */