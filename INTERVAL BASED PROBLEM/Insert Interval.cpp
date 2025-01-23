class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // Get the number of existing intervals
        int n = intervals.size();
        int i = 0; // To keep track of the current interval
        vector<vector<int>> result; // Vector to store the result with merged intervals

        // Traverse through the intervals
        while (i < n) {
            // If the current interval ends before the new interval starts (no overlap)
            if (intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]); // Add the current interval to the result
            }
            // If the current interval starts after the new interval ends (no overlap)
            else if (intervals[i][0] > newInterval[1]) {
                break; // No need to process further intervals, as they are all after the new interval
            }
            // If there's an overlap between the current interval and the new interval
            else if (intervals[i][1] >= newInterval[0]) {
                // Merge the current interval with the new interval
                newInterval[0] = min(newInterval[0], intervals[i][0]); // Update the start of the new interval
                newInterval[1] = max(newInterval[1], intervals[i][1]); // Update the end of the new interval
            }
            i++; // Move to the next interval
        }

        // After processing all overlapping intervals, add the merged new interval to the result
        result.push_back(newInterval);

        // Add all remaining intervals (non-overlapping) to the result
        while (i < n) {
            result.push_back(intervals[i]);
            i++; // Move to the next interval
        }

        // Return the result with the merged new interval inserted
        return result;
    }
};
