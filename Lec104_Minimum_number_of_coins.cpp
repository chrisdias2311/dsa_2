#include<iostream>
#include<vector>
#include<list>
using namespace std;


// APPROACH 1 : RECURSION based brute force
int solveRecursion(vector<int> &num, int x){
    //Base case 
    if(x==0)
        return 0;
    if(x<0)
        return INT_MAX
    
    int mini = INT_MAX;

    for(int i=0; i<num.size; i++){
        int ans = solveRecursion(num, x-nums[i]);
        if(ans != INT_MAX)
            mini  = min(mini, 1+ans)
    }

    return mini;
}

int minimumElements(vector<int> &num, int x){
    // Write your code here.
    int ans = solveRecursion(num, x);
    if(ans!=INT_MAX)
        return -1;

}






//APPRIOACH 2 : MEMOIZATION based DP     (Top Down approach)

int solveMemoisation(vector<int> &num, int x, vector<int> &dp){
    //Base case 
    if(x==0)
        return 0;
    if(x<0)
        return INT_MAX;
    
    if(dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int ans = solveMemoisation(num, x-num[i], dp);
        if(ans != INT_MAX)
            mini  = min(mini, 1+ans);
    }

    dp[x] = mini;
    return mini;
}

int minimumElements(vector<int> &num, int x){

    // Recursion + Memoisation 
    //Here X is the target sum 
    vector<int> dp(x+1, -1);    // Vector of size amount+1 and initialize it with -1;
    int ans = solveMemoisation(num, x, dp);

    if(ans==INT_MAX)
        return -1;
    else 
        return ans;

}









//Approach 3 : Tabulation based DP     (Bottom Up approach)
int solveTabulation(vector<int> &num, int x){
   vector<int> dp(x+1, INT_MAX);  //Create vector of size x+1 and initialize it with INT_MAX 
   dp[0] = 0;   // Here dp[i] indicates minimum number of coins required to make target i 

   for(int i=1; i<=x; i++){
       // Here we try to solve for every amount figure from 1 to X
       for(int j=0; j<num.size(); j++){     

           if(i-num[j] >=0 && dp[i-num[j]]!=INT_MAX){         //(7-2>=0 && dp[7-2]!=nt_max)
                dp[i] = min(dp[i], 1+dp[i-num[j]]);           //dp[7] = min(dp[7], 1+dp[7-2])   min(INT_MAX, 1+dp[5])        Also here we add in 1 so that we can add the coin we are using to make the sum
           }
           
       }
   }

    if(dp[x]==INT_MAX)
        return -1;
    else 
        return dp[x];
}

int minimumElements(vector<int> &num, int x){

    // Using tabulation method 
    return solveTabulation(num, x);

}