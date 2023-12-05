class Solution {
public:
    
    long long findMinCoin(int i, vector<int>& coins, long long amount, vector<vector<int>>& dp) {
    if (amount < 0) return 20000;
    if (amount == 0 ) return 0;
    if ( i == coins.size() && amount != 0 ) return 20000 ;

    if ( dp[i][amount] != -1 )   return dp[i][amount] ;
    long long again = 1 + findMinCoin(i, coins, amount - coins[i], dp);
    //long long nxt = 1 + findMinCoin(i + 1, coins, amount - coins[i], dp);
    long long skip = findMinCoin(i + 1, coins, amount, dp);

    
    return dp[i][amount] = min(again, skip) ;
}

int coinChange(vector<int>& coins, int amount) 
{
    vector<vector<int>>dp(coins.size()+1,vector<int>(10001,-1)) ;
    int ans =  findMinCoin(0, coins, amount, dp);
    return ((ans >= 20000)? -1 : ans);
}

};