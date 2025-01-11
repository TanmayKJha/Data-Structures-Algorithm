class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        // Initialize variables
        int n = nums.size();          // Size of the input array
        int minLen = INT_MAX;         // Minimum length of the subarray that satisfies the condition (initialized to a large value)
        int i = 0;                    // Start pointer of the sliding window
        int j = 0;                    // End pointer of the sliding window
        int sum = 0;                  // Running sum of the current window

        // Start iterating over the array using the end pointer (j)
        while (j < n) {
            // Add the current element to the sum
            sum += nums[j];

            // Check if the current window sum meets or exceeds the target
            while (sum >= target) {
                // Update the minimum length of the subarray if the current window is smaller
                minLen = min(minLen, j - i + 1);

                // Shrink the window from the left by removing the element at index i
                sum -= nums[i];

                // Move the start pointer (i) to the right
                i++;
            }

            // Expand the window by moving the end pointer (j) to the right
            j++;
        }
        
        // If no valid subarray was found, return 0; otherwise, return the minimum length
        return minLen == INT_MAX ? 0 : minLen;
    }
};
