#include<iostream>
#include<vector>
using namespace std;


// Approach 1 (Using top down appraoach i.e Recursion + Memoization)     
// Time complexity O(n) 
// Space complexity O(n)+O(n)

int fib(int n, vector<int> &dp){
        // Base case 
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        
        // Step 2
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
}

int main(){
    int n;
    cin>>n;

    // Step 1
    vector<int> dp(n+1);

    for(int i=0; i<=n; i++)
        dp[i] = -1;

    cout<< fib(n, dp) <<endl;

    return 0;
}








// Approach 2 using Bottom up approach (Tabulation method)
// Time complexity O(n)
// Space complexity => O(n) (Better than Approach 1)
// int main(){
//         int n;
//         cin>>n;
        
//         // Step 1
//         vector<int> dp(n+1);
        
//         //Step 2
//         dp[0] = 0;
//         dp[1] = 1;

//         //Step 3
//         for(int i=2; i<=n; i++)
//             dp[i] = dp[i-1]+dp[i-2];
        
//         cout<<dp[n];
        
// }






// // Approach 3 using apce optimization 
// Time complexity => O(n)
// Space complexity O(1)
// int main(){
//     int n;
//     cin>>n;
        
//     int prev1 = 1;
//         int prev2 = 0;

//     if(n==2)
//         return prev2;

//     for(int i=2; i<=n; i++){
//         int curr = prev1 + prev2;
                
//         //Shift logic 
//         prev2 = prev1;
//         prev1 = curr;
//     }

//     cout<<prev1;
        
// }