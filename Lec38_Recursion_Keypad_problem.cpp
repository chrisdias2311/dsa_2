
class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);

            //Backtrack step
            output.pop_back();     //Make the string empty for the top level
        }
        
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.length()==0)
            return ans;

        string output;
        int index=0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, index, ans, mapping);
        return ans;

    }
};