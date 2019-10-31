/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (24.92%)
 * Likes:    676
 * Dislikes: 1899
 * Total Accepted:    125.4K
 * Total Submissions: 497.9K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 2^31 - 1.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: "One Hundred Twenty Three"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * 
 * Example 3:
 * 
 * 
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
            digitName = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        tenthName = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        tyName = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> segs(4, "");
        int idx = 0;
        while (num) {
            toHundred(segs[idx], num % 1000);
            num /= 1000;
            ++idx;
        }
        string result = "";
        const vector<string> names{"", " Thousand", " Million", " Billion"};
        bool needBlank = false;
        while (idx--) {
            if (!segs[idx].empty()) {
                result += (needBlank ? " " : "") + segs[idx] + names[idx];
                needBlank = true;
            }
        }
        return result;
    }
private:
    vector<string> digitName;
    vector<string> tenthName;
    vector<string> tyName;
    void toHundred(string &s, int num) {
        string h = "", t = "", o = "";
        int digits = num % 10;
        if (digits)
            o = digitName[digits-1];
        num /= 10;
        int tens = num % 10;
        if (tens == 1) {
            o = "";
            t = tenthName[digits];
        }
        else if (tens)
            t = tyName[tens - 2] + (digits ? " ": "");
        num /= 10;
        int hundreds = num;
        if (hundreds)
            h = digitName[hundreds-1] + " Hundred" + (digits || tens ? " " : "");
        s = h + t + o;
    }
};
// @lc code=end
