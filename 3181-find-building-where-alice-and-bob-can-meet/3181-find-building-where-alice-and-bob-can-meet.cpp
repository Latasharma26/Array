#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTree {
public:
    int n;
    vector<int> segmentTree;
    vector<int> nums;

    SegmentTree(const vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        int power = 1;
        while (power < n) {
            power *= 2;
        }
        segmentTree.resize(2 * power - 1, INT_MIN);
        buildTree(0, n - 1, 0);
    }

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

    int getMaxInRange(int queryLow, int queryHigh) {
        return getMaxInRangeHelper(0, n - 1, 0, queryLow, queryHigh);
    }

    int getMaxInRangeHelper(int low, int high, int position, int queryLow, int queryHigh) {
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
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        SegmentTree st(heights);
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int a = min(queries[i][0], queries[i][1]);
            int b = max(queries[i][0], queries[i][1]);
            if (a == b) {
                res[i] = a;
                continue;
            }
            if (heights[b] > heights[a]) {
                res[i] = b;
                continue;
            }

            res[i] = -1;
            int h = max(heights[a], heights[b]);

            int l = b;
            int r = heights.size() - 1;
            int mid;

            while (l <= r) {
                mid = l + (r - l) / 2;
                if (st.getMaxInRange(b, mid) > h) {
                    res[i] = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return res;
    }
};