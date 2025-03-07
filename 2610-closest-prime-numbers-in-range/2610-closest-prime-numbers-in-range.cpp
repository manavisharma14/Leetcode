#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:

    vector<bool> sieveOfEratosthenes(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
        return prime; // Return the sieve array
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime = sieveOfEratosthenes(right); // Compute primes up to 'right'
        vector<int> primesInRange;

        // Collect primes in the range [left, right]
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                primesInRange.push_back(i);
            }
        }

        // If less than 2 primes exist, return {-1, -1}
        if (primesInRange.size() < 2) return {-1, -1};

        // Find the closest prime pair
        int minDiff = INT_MAX;
        vector<int> result(2, -1);

        for (int i = 1; i < primesInRange.size(); i++) {
            int diff = primesInRange[i] - primesInRange[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = primesInRange[i - 1];
                result[1] = primesInRange[i];
            }
        }

        return result;
    }
};

