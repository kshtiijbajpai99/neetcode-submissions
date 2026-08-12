class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int target, int index,
                   vector<int>& curr) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            // Same level par duplicate ko skip karo
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Agar number target se bada hai
            if (nums[i] > target) {
                break;
            }

            curr.push_back(nums[i]);

            // i + 1 -> same element dobara use nahi hoga
            backtrack(nums, target - nums[i], i + 1, curr);

            // Undo
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<int> curr;

        backtrack(nums, target, 0, curr);

        return ans;
    }
};