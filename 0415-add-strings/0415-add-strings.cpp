class Solution {
public:
    string addStrings(string num1, string num2) {
        int c = 0 ;
        
        string ans = "" ;
        int a = num1.size() ;
        int b = num2.size() ;
        
        int i = a-1, j = b-1 ;
        while ( i >= 0 && j >= 0 )
        {
            int sum = int(num1[i]-'0') + int(num2[j]-'0') + c ;
            if ( sum > 9 )
            {
                c = 1 ;
                ans = to_string(sum%10) + ans ;
            }
            else
            {
                ans = to_string(sum) + ans ;
                c = 0 ;
            }
            i-- ;
            j-- ;
        }
        while ( i >= 0 )
        {
            if ( int(num1[i]-'0') + c > 9 )
            {
                c = 1 ;
                ans = to_string((int(num1[i]-'0') + c)%10) + ans ;
            }
            else 
            {
                ans = to_string(int(num1[i]-'0') + c) + ans ;
                c = 0 ;
            }
            i-- ;
        }
        while ( j >= 0 )
        {
            if ( int(num2[j]-'0') + c > 9 )
            {
                c = 1 ;
                ans = to_string((int(num2[j]-'0') + c)%10) + ans ;
            }
            else 
            {
                ans = to_string(int(num2[j]-'0') + c) + ans ;
                c = 0 ;
            }
            j-- ;
        }
        if ( c == 1 )
             ans = "1" + ans ;
       
        return ans ;
        
    }
};