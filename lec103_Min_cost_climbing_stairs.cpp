// There is a staircase and we have to climb it. Before crossing any stair we have to pay the cost mentioned for that stair in such a way that the total cost at the end should be minimum 

class Solution {
public:
    int solve(vector<int>& cost, int n){
        //BASE CASE
        //Have arrived from the most obottom step 
        if(n==0)
            return cost[0];
        //Have arrived from the first step 
        if(n==1)
            return cost[1]; 

        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));  // (Eg: for last step) cost of existing step + min(solve(cost, n-1), solve(cost, n-2))
        return ans;
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //It can be simplified more -> HOMEWORK
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};







//TOP DOWN APPROACH    (Recursion + Memoization )

class Solution {
public:
    int solve2(vector<int>& cost, int n, vector<int> &dp){
        //BASE CASE
        //Have arrived from the most obottom step 
        if(n==0)
            return cost[0];
        //Have arrived from the first step 
        if(n==1)
            return cost[1]; 
        
        //STEP 3 
        if(dp[n] != -1)
            return dp[n];

        //STEP 2
        dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));  
        return dp[n];
    }


    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        //STEP 1;
        vector<int> dp(n+1, -1);
        int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return ans;
    }
};







//BOTTOM UP APPROACH       (Tabulation method)
class Solution {
public:
    int solve3(vector<int>& cost, int n){
        // Step 1: Creation of DP array
        vector<int> dp(n+1);

        //Step 2: Analyse the base case 
        dp[0] = cost[0];
        dp[1] = cost[1];

        //Step 3: 
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }


    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        return solve3(cost, n);
    }
};