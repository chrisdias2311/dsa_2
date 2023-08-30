#include<iostream>
using namespace std;
#include<vector>


// RecursioN based approach     (TLE due to exponential time complexity)

int solve(vector<int> &nums, int n){
    //base case
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];
    
    int incl = solve(nums, n-2) + nums[n];   //include nums[i] & move the pointer 2 steps towards left 
    int excl = solve(nums, n-1) + 0;         //exclude nums[i] & move the pointer 1 step towards left 

    return max(incl, excl);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int ans = solve(nums, n-1);    //Here we are traversing from right to left hence we send the last element i.e. n-1th element 

    return ans; 
}









//Recursion + Memoization based approach 
#include<iostream>
using namespace std;
#include<vector>


int solve(vector<int> &nums, int n, vector <int> &dp){
    //base case
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];
    if(dp[n]!=-1)
        return dp[n];
    
    int incl = solve(nums, n-2, dp) + nums[n];   //include nums[i] & move the pointer 2 steps towards left 
    int excl = solve(nums, n-1, dp) + 0;         //exclude nums[i] & move the pointer 1 step towards left 

    dp[n] = max(incl, excl);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, n-1, dp);

}






// Method 3 using Tabulation method
#include<iostream>
using namespace std;
#include<vector>
int solveTabulation(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;

        dp[i] = max(incl, excl);
    }
    return dp[n-1];

}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();
    // vector<int> dp(n, -1);
    return solveTabulation(nums);

}











// Pscae optimization based approach    (Here we are using only 2 variables instead of an array)


int solveSpaceOpt(vector<int> &nums){
    int n = nums.size();
    
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1; i<n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;

}

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n = nums.size();
    // vector<int> dp(n, -1);
    return solveSpaceOpt(nums);

}