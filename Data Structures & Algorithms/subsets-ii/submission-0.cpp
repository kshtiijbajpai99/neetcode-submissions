class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index,
                   vector<int>& current) {

        // Har current subset valid hai
        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            // Same level par duplicate ko skip karo
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Choose
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, i + 1, current);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Duplicates ko paas-paas laane ke liye
        sort(nums.begin(), nums.end());

        vector<int> current;

        backtrack(nums, 0, current);

        return ans;
    }
};