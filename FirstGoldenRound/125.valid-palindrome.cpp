/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (31.17%)
 * Total Accepted:    368K
 * Total Submissions: 1.2M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size()-1; i < j; ++i, --j) {
            while (!isalnum(s[i]) && i < j) ++i;
            while (!isalnum(s[j]) && i < j) --j;
            char front = tolower(s[i]),
                 end   = tolower(s[j]);
            if (front != end) {
                std::cout << s[i] << s[j] <<std::endl;
                return false;}
        }
        
        return true;
    }
};
