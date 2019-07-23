/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.03%)
 * Total Accepted:    245.6K
 * Total Submissions: 839.9K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n==1 || n==2) return 0;
        int counts = n / 2; //there are at most n/2 primes (2 and odd numbers except 1)        
        int sqrtn = sqrt(n); 

        vector<bool> excluded(n, false);
        for (unsigned e = 3; e <= sqrtn; e += 2) {
            if (excluded[e] == true) continue;
            for (int composite = e * e; composite < n; composite += 2 * e) {
                if (excluded[composite] == false) {
                    --counts;
                    excluded[composite] = true;
                    //if (composite == 9999)
                      //  cout << e << "\t:\t9999" << endl;
                }
            }
        }
        return counts;
    }
};
