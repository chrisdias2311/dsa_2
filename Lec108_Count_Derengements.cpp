#define MOD 1000000007

// Approach 1 recursion based approach 
long long int countDerangements(int n) {
    //Base case
    if(n==1)
        return 0;
    
    if(n==2)
        return 1;

    int ans = (((n-1)%MOD)*((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD)))%MOD;

    return ans;
}




/// Approach 2 recursion and memoisation based approach 
#define MOD 1000000007
#include<vector> 

int solveMem(int n, vector<long long int>& dp){
    //base case 
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    if(dp[n] != -1)
        return dp[n];

    dp[n] = (((n-1)%MOD)*((solveMem(n-1,dp)%MOD) + (solveMem(n-2,dp)%MOD)))%MOD;

    return dp[n];
}

long long int countDerangements(int n) {
    
    vector<long, long int> dp(n+1, 1);
    return solveMem(n, dp);
}







//Approach 3 Tabulation based approach 
long long int solveTab(int n){
    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD; 
        long long int sum = (first+second)%MOD;
        long long int ans = ((n-1)*sum)%MOD;
        dp[i] = ans;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    
    vector<long, long int> dp(n+1, 1);
    r