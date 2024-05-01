class Solution {
public:
    
    void findAns ( string &ans, int k )
    {
        string temp = "" ;
        int a = 0, cSum = 0 ;
        for ( int i = 0 ; i < ans.size() ; i++ )
        {
            a++ ;
            cSum += ans[i]-'0' ;
            
            if ( a == k || i == ans.size()-1 )
            {
                temp += to_string(cSum) ;
                cSum = 0 ;
                a = 0 ;
            }
        }
        ans = temp ;
    }
    
    
    string digitSum(string s, int k) {
//         string ans = "" ;
//         int a = 0 ;
//         int cSum = 0 ;
//         for ( int i = 0 ; i < s.size() ; i++ )
//         {
//             a++ ;
//             cSum += s[i]-'0' ;
            
//             if ( a == k || i == s.size()-1 )
//             {
//                 ans += to_string(cSum) ;
//                 cSum = 0 ;
//                 a = 0 ;
//             }
//         }
        
        while ( s.size() > k )
        {
            findAns( s, k ) ;
        }
        return s ;
    }
};