class Solution {
public:
    int trap(vector<int>& height) {

        // Left pointer
        int left = 0;

        // Right pointer
        int right = height.size() - 1;

        // Highest wall seen from left
        int leftMax = 0;

        // Highest wall seen from right
        int rightMax = 0;

        // Stores total trapped water
        int water = 0;

        // Continue until pointers meet
        while (left < right) {

            // Always process the smaller side
            if (height[left] <= height[right]) {

                // Update leftMax if current wall is taller
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                // Otherwise water is trapped
                else {
                    water += leftMax - height[left];
                }

                // Move left pointer
                left++;
            }
            else {

                // Update rightMax if current wall is taller
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                }
                // Otherwise water is trapped
                else {
                    water += rightMax - height[right];
                }

                // Move right pointer
                right--;
            }
        }

        return water;
    }
};