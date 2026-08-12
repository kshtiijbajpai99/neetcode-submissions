class Solution {
public:

vector<vector<int>>ans;
void backtrack(vector<int>& nums, int target,int index,vector<int>&curr){
    if(target==0){
        ans.push_back(curr);
        return;
    }
    if(target<0)return;

    for(int i=index;i<nums.size();i++){
        curr.push_back(nums[i]);

        backtrack(nums,target-nums[i],i,curr);

        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        backtrack(nums,target,0,curr);

        return ans;
    }
};
