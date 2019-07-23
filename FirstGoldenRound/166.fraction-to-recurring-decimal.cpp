/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (19.60%)
 * Total Accepted:    90.5K
 * Total Submissions: 461.5K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * 
 * 
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string result = "";
        int negative = numerator > 0 ^ denominator > 0;
        if (negative)
            result += "-";
        long long nu = labs(numerator), de = labs(denominator);
        long long integer = nu / de;
        result += to_string(integer);
        long long rem = nu % de;
        if (rem == 0)
            return result;
        result += ".";
        unordered_map<long long, int> lookup;
        lookup[rem] = result.length();
        while (rem) {
            rem *= 10;
            integer = rem / de;
            result += to_string(integer);

            rem = rem % de;
            if (lookup.find(rem) == lookup.end())
                lookup[rem] = result.length();
            else {
                result.insert(lookup[rem], "(");
                result += ")";
                break;
            }
        }
        return result;
    }
};
