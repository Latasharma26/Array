#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class SegmentTree {
    vector<int> segmentTree;
    vector<int> nums;
    int n;

    void buildTree(int low, int high, int position) {
        if (low == high) {
            segmentTree[position] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;

        buildTree(low, mid, 2 * position + 1);
        buildTree(mid + 1, high, 2 * position + 2);
        segmentTree[position] = max(segmentTree[2 * position + 1], segmentTree[2 * position + 2]);
    }

    void updateTree(int low, int high, int position, int index, int val) {
        if (index < low || index > high) {
            return;
        }

        if (low == high) {
            nums[index] = val;
            segmentTree[position] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        updateTree(low, mid, 2 * position + 1, index, val);
        updateTree(mid + 1, high, 2 * position + 2, index, val);

        segmentTree[position] = max(segmentTree[2 * position + 1], segmentTree[2 * position + 2]);
    }

    int getMaxInRangeHelper(int low, int high, int position, int queryLow, int queryHigh) const {
        if (low > queryHigh || high < queryLow) {
            return INT_MIN;
        }

        if (low >= queryLow && high <= queryHigh) {
            return segmentTree[position];
        }

        int mid = low + (high - low) / 2;
        int leftMax = getMaxInRangeHelper(low, mid, 2 * position + 1, queryLow, queryHigh);
        int rightMax = getMaxInRangeHelper(mid + 1, high, 2 * position + 2, queryLow, queryHigh);

        return max(leftMax, rightMax);
    }

public:
    SegmentTree(const vector<int>& nums) : nums(nums), n(nums.size()) {
        int length = 1;
        while (length < n) length *= 2;
        segmentTree.assign(2 * length - 1, INT_MIN);
        buildTree(0, n - 1, 0);
    }

    void update(int index, int val) {
        updateTree(0, n - 1, 0, index, val);
    }

    int getMaxInRange(int queryLow, int queryHigh) const {
        return getMaxInRangeHelper(0, n - 1, 0, queryLow, queryHigh);
    }
};

class Solution {
    int bs(const vector<vector<int>>& items, int q) {
        int res = -1;
        int l = 0;
        int r = items.size() - 1;
        int mid;

        while (l <= r) {
            mid = l + (r - l) / 2;

            if (items[mid][0] <= q) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<int> beauties(items.size());
        for (int i = 0; i < items.size(); i++) {
            beauties[i] = items[i][1];
        }

        SegmentTree st(beauties);
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int indexR = bs(items, queries[i]);
            res[i] = (indexR == -1) ? 0 : st.getMaxInRange(0, indexR);
        }

        return res;
    }
};
