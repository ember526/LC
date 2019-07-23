/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 *
 * https://leetcode.com/problems/alien-dictionary/description/
 *
 * algorithms
 * Hard (31.39%)
 * Total Accepted:    82.1K
 * Total Submissions: 260.3K
 * Testcase Example:  '["wrt","wrf","er","ett","rftt"]'
 *
 * There is a new alien language which uses the latin alphabet. However, the
 * order among letters are unknown to you. You receive a list of non-empty
 * words from the dictionary, where words are sorted lexicographically by the
 * rules of this new language. Derive the order of letters in this language.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ "wrt",
 * ⁠ "wrf",
 * ⁠ "er",
 * ⁠ "ett",
 * ⁠ "rftt"
 * ]
 * 
 * Output: "wertf"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ⁠ "z",
 * ⁠ "x"
 * ]
 * 
 * Output: "zx"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * [
 * ⁠ "z",
 * ⁠ "x",
 * ⁠ "z"
 * ] 
 * 
 * Output: "" 
 * 
 * Explanation: The order is invalid, so return "".
 * 
 * 
 * Note:
 * 
 * 
 * You may assume all letters are in lowercase.
 * You may assume that if a is a prefix of b, then a must appear before b in
 * the given dictionary.
 * If the order is invalid, return an empty string.
 * There may be multiple valid order of letters, return any one of them is
 * fine.
 * 
 * 
 */
class Solution {
public:
    string alienOrder(vector<string>& words) {
        //Topological Sort
        if (words.empty())
            return "";
        //D.S.
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        //Initialize indegree to 0
        for (string s : words)
            for (char ch : s)
                indegree[ch] = 0;
        //Build the graph according to letter orders
        for (int i = 0; i < words.size() - 1; ++i) {
            //Only two consequent words are used to deduce letter orders
            string cur = words[i], next = words[i+1];
            int len = min (cur.length(), next.length());
            for (int j = 0; j < len; ++j) {
                if (cur[j] == next[j])
                    continue;
                auto &set = graph[cur[j]];
                //No need to add the same order again
                if (set.find(next[j]) == set.end()) {
                    set.insert(next[j]);
                    ++indegree[next[j]];
                }
                break;
            }
        }
        //Topological Sort
        string result = "";
            //step 1 : enqueue all the nodes with 0 indegree, they are the start points
        queue<char> zero;
        for (auto iter : indegree) {
            if (iter.second == 0)
                zero.push(iter.first);
        }
            //step 2 : traverse from these points
        while (zero.empty() == false) {
            auto top = zero.front();
            zero.pop();
            result += top;

            for (char ch : graph[top]) {
                if (--indegree[ch] == 0)
                    zero.push(ch);
            }
        }
        //Circles result in nonzero values in the final indegree vector
        return result.length() == indegree.size() ? result : "";
    }
};
