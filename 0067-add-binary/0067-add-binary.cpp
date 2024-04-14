class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1 , j = b.size()-1 ;
        int c = 0 ;
        
        
        string ans = "" ;
        while ( i >= 0 && j >= 0 )
        {
            
            if ( int(a[i]-'0') + int(b[j]-'0') + c == 0 )
            {
                c = 0 ;
                ans = "0" + ans ;
            }
            else if ( int(a[i]-'0') + int(b[j]-'0') + c == 1 )
            {
                c = 0 ;
                ans = "1" + ans ;
            }
            else if ( int(a[i]-'0') + int(b[j]-'0') + c == 2 )
            {
                c = 1 ;
                ans = "0" + ans ;
            }
            else if ( int(a[i]-'0') + int(b[j]-'0') + c == 3 )
            {
                c = 1 ;
                ans = "1" + ans ;
            }
            i-- ;
            j-- ;
        }
        while ( i >= 0 )
        {
            if ( int(a[i]-'0') + c == 0 )
            {
                c = 0 ;
                ans = "0" + ans ;
            }
            else if ( int(a[i]-'0') + c == 1 )
            {
                c = 0 ;
                ans = "1" + ans ;
            }
            else if ( int(a[i]-'0') + c == 2 )
            {
                c = 1 ;
                ans = "0" + ans ;
            }
            i-- ;                 
                
        }
        while ( j >= 0 )
        {
            if ( int(b[j]-'0') + c == 0 )
            {
                c = 0 ;
                ans = "0" + ans ;
            }
            else if ( int(b[j]-'0') + c == 1 )
            {
                c = 0 ;
                ans = "1" + ans ;
            }
            else if ( int(b[j]-'0') + c == 2 )
            {
                c = 1 ;
                ans = "0" + ans ;
            }
            j-- ;                 
                
        }
                     
        if ( c == 1 )
            ans = "1" + ans ;
        return ans ;
    }
};