#include <iostream>
#include <vector>
using namespace std;

class SieveOfEratosthenes {
public:
    vector<int> generatePrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        initializeSieve(isPrime, limit);
        applySieve(isPrime, limit);
        collectPrimes(isPrime, primes, limit);

        return primes;
    }

private:
    void initializeSieve(vector<bool>& isPrime, int limit) {
        for (int i = 2; i <= limit; i++) {
            isPrime[i] = true;
        }
    }

    void applySieve(vector<bool>& isPrime, int limit) {
        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    void collectPrimes(const vector<bool>& isPrime, vector<int>& primes, int limit) {
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
    }
};

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        SieveOfEratosthenes sieve;
        vector<int> primes = sieve.generatePrimes(1000);

        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] >= nums[i]) {
                int target = nums[i - 1] - nums[i] + 1;
                int primeT = find(primes, target);
                if (primeT == -1) {
                    return false;
                }
                nums[i - 1] = nums[i - 1] - primeT;
                if (nums[i - 1] < 1) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    int find(const vector<int>& sieve, int target) {
        int l = 0;
        int r = sieve.size() - 1;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (sieve[mid] == target) {
                return target;
            }
            if (sieve[mid] > target) {
                r = mid - 1;
                res = sieve[mid];
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
