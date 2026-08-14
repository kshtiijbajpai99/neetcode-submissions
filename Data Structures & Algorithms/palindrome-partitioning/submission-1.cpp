class Solution {
public:

    vector<vector<string>> ans;

    bool palindrome(string& s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int index, vector<string>& curr) {

        // Entire string partitioned
        if(index == s.size()) {
            ans.push_back(curr);
            return;
        }

        // Try every possible substring
        for(int i = index; i < s.size(); i++) {

            // Skip if substring is not palindrome
            if(!palindrome(s, index, i))
                continue;

            // Choose
            curr.push_back(s.substr(index, i - index + 1));

            // Explore
            backtrack(s, i + 1, curr);

            // Undo
            curr.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> current;

        backtrack(s, 0, current);

        return ans;
    }
};