#include<iostream>
#include<vector>
using namespace std;

long long int solveTabulation(vector<int> &nums){
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

long long int houseRobber(vector<int>& valueInHouse){
    int n = valueInHouse.size();

    if(n==1)
        return valueInHouse[0];

    vector<int> first, second;

    for(int i=0; i<n; i++){
        if(i != n-1)
            first.push_back(valueInHouse[i]);
        if(i != 0)
            second.push_back(valueInHouse[i]);
    }

    return max(solveTabulation(first), solveTabulation(second));
}