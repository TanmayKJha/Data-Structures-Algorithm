class Solution {
public:
    // Recursive function to generate all combinations
    void solve(int start, int k, vector<int>& temp, vector<vector<int>>& result, int n) {
        
        // Base case: If k elements are selected, add the current combination to result
        if (k == 0) {
            result.push_back(temp);
            return;
        }

        // If start exceeds n, return (no more numbers left to pick)
        if (start > n) return;

        // **Include the current number** in the combination
        temp.push_back(start);
        solve(start + 1, k - 1, temp, result, n); // Move to the next number with k-1 elements left

        // **Exclude the current number** (Backtracking step)
        temp.pop_back();  // Undo the choice
        solve(start + 1, k, temp, result, n); // Move to the next number without reducing k
    }

    // Main function to generate all k-combinations of numbers from 1 to n
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp; // Stores the current combination
        vector<vector<int>> result; // Stores all valid combinations

        solve(1, k, temp, result, n); // Start recursion from 1
        return result; // Return the list of all possible combinations
    }
};
