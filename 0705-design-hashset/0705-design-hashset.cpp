class MyHashSet {
public:
    
    vector<bool>ds ;
    
    MyHashSet() : ds( 1e6+1, false ) {

    }
    
    void add(int key) {
        ds[key] = true ;
    }
    
    void remove(int key) {
        ds[key] = false ;
    }
    
    bool contains(int key) {
        return ds[key] ;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */