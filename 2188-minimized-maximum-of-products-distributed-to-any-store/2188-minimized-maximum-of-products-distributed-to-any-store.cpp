class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int res = 1e5;
        int l = 1;
        int r = 1e5;
        int mid;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (check(quantities, n, mid)) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return res;
    }

private:
    bool check(vector<int>& quantities, int n, int max) {
        int c = 0;

        for (int q : quantities) {
            c += (q % max == 0) ? (q / max) : (q / max + 1);
            if (c > n) {
                return false;
            }
        }

        return c <= n;
    }
};
