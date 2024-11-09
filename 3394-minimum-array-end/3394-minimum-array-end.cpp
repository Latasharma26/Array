#include <cstdint>

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = static_cast<long long>(x);
        long long remaining = n - 1;
        long long position = 1;

        while (remaining > 0) {
            if ((x & position) == 0) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }

        return result;
    }
};
