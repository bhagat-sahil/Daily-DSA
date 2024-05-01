class Solution {
public:
    
    void findAns ( string & s )
    {
        int sum = 0 ;
        for ( int i = 0 ; i < s.size() ; i++ )
        {
            sum += s[i]-'0' ;
        }
        s = to_string( sum ) ;
    }
    
    
    int addDigits(int num) {
        string s = to_string(num) ;
        
        while ( s.size() > 1 )
        {
            findAns( s ) ;
        }
        return stoi(s) ;
    }
};