class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;      // Index store karega
        vector<int> ans;    // Final answer

        for (int i = 0; i < nums.size(); i++) {

            // =====================================================
            // STEP 1 : Agar koi index window ke bahar chala gaya hai
            // to usko hata do.
            //
            // Example:
            // Window = [3 4 5]
            // Agar deque me index = 2 hai
            // To wo bahar hai -> Remove
            // =====================================================
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();


            // =====================================================
            // STEP 2 : Current element bada hai?
            //
            // Example:
            // Deque values = 9 7 5
            // Current = 6
            //
            // 6 > 5 -> Remove 5
            // 6 > 7 -> No
            // Stop
            //
            // Kyuki 5 future me kabhi maximum nahi banega.
            // =====================================================
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();


            // =====================================================
            // STEP 3 : Current index ko deque me daal do.
            // =====================================================
            dq.push_back(i);


            // =====================================================
            // STEP 4 : Jab first window complete ho jaye
            //
            // Example:
            // k = 3
            //
            // i=0 -> Window incomplete
            // i=1 -> Window incomplete
            // i=2 -> First window complete
            //
            // Deque ka front hamesha maximum hota hai.
            // =====================================================
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};