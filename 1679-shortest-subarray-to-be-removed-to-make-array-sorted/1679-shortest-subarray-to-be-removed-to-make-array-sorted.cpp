#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int max1 = 1, max2 = 1, max3 = INT_MAX;
        int n = arr.size();

        // Calculate max1
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                max1++;
            } else {
                break;
            }
        }
        int l = max1 - 1;
        max1 = n - max1;

        // Calculate max2
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) {
                max2++;
            } else {
                break;
            }
        }
        max2 = n - max2;

        // If max1 or max2 is 0, return 0
        if (max1 == 0 || max2 == 0) {
            return 0;
        }
        int r = max2;

        // Calculate max3
        for (int i = r; i < n; i++) {
            int index = bs(arr, l, arr[i]);
            if (index != -1) {
                max3 = min(max3, n - (index + 1 + n - i));
            }
        }

        return min({max1, max2, max3});
    }

private:
    int bs(const vector<int>& nums, int r, int target) {
        int l = 0, mid;
        int res = -1;

        while (l <= r) {
            mid = l + (r - l) / 2;

            if (nums[mid] <= target) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
