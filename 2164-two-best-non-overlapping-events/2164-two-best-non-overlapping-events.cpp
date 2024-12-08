class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
         sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by end time
        });

        // Prefix max to store the maximum value seen so far
        int max_value = 0;
        vector<int> prefix_max(events.size());
        vector<int> end_times;

        // Fill prefix_max and end_times
        for (int i = 0; i < events.size(); ++i) {
            max_value = max(max_value, events[i][2]);
            prefix_max[i] = max_value;
            end_times.push_back(events[i][1]);
        }

        // Step 2: Iterate through events and calculate the maximum sum
        int result = 0;
        for (int i = 0; i < events.size(); ++i) {
            int start = events[i][0], end = events[i][1], value = events[i][2];

            // Binary search for the last non-overlapping event
            auto it = upper_bound(end_times.begin(), end_times.end(), start - 1);
            if (it != end_times.begin()) {
                int idx = (it - end_times.begin()) - 1;
                result = max(result, value + prefix_max[idx]);
            }

            // Consider the case of only choosing the current event
            result = max(result, value);
        }

        return result;
    }
};