/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (40.87%)
 * Total Accepted:    9K
 * Total Submissions: 22.1K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * Given an array equations of strings that represent relationships between
 * variables, each string equations[i] has length 4 and takes one of two
 * different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not
 * necessarily different) that represent one-letter variable names.
 * 
 * Return true if and only if it is possible to assign integers to variable
 * names so as to satisfy all the given equations.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is
 * satisfied, but not the second.  There is no way to assign the variables to
 * satisfy both equations.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["a==b","b==c","a==c"]
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: ["a==b","b!=c","c==a"]
 * Output: false
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: ["c==c","b==d","x!=z"]
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] and equations[i][3] are lowercase letters
 * equations[i][1] is either '=' or '!'
 * equations[i][2] is '='
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class DSU {
public:
    DSU() : p_(26) {
        iota(p_.begin(), p_.end(), 0);
    }

    void Union(const char X, const char Y) {
        p_[Find(X - 'a')] = p_[Find(Y - 'a')];
    }

    bool Check(const char X, const char Y) {
        return Find(X - 'a') != Find(Y - 'a');
    }
private:
    vector<int> p_;
    int Find(const int a) {
        if (p_[a] != a)
            p_[a] = Find(p_[a]);
        return p_[a];
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;
        vector<pair<char, char>> checklist;
        for (const auto &e : equations) {
            const char X = e[0], Y = e[3];
            if (e[1] == '=')
                dsu.Union(X, Y);
            else
                checklist.push_back(make_pair(X, Y));
        }

        for (const auto &p : checklist)
            if (dsu.Check(p.first, p.second) == false)
                return false;

        return true;
    }
};
