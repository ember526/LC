/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 *
 * https://leetcode.com/problems/accounts-merge/description/
 *
 * algorithms
 * Medium (41.82%)
 * Total Accepted:    39.5K
 * Total Submissions: 94.4K
 * Testcase Example:  '[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]'
 *
 * Given a list accounts, each element accounts[i] is a list of strings, where
 * the first element accounts[i][0] is a name, and the rest of the elements are
 * emails representing emails of the account.
 * 
 * Now, we would like to merge these accounts.  Two accounts definitely belong
 * to the same person if there is some email that is common to both accounts.
 * Note that even if two accounts have the same name, they may belong to
 * different people as people could have the same name.  A person can have any
 * number of accounts initially, but all of their accounts definitely have the
 * same name.
 * 
 * After merging the accounts, return the accounts in the following format: the
 * first element of each account is the name, and the rest of the elements are
 * emails in sorted order.  The accounts themselves can be returned in any
 * order.
 * 
 * Example 1:
 * 
 * Input: 
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
 * "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
 * "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * Output: [["John", 'john00@mail.com', 'john_newyork@mail.com',
 * 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary",
 * "mary@mail.com"]]
 * Explanation: 
 * The first and third John's are the same person as they have the common email
 * "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email
 * addresses are used by other accounts.
 * We could return these lists in any order, for example the answer [['Mary',
 * 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
 * would still be accepted.
 * 
 * 
 * 
 * Note:
 * The length of accounts will be in the range [1, 1000].
 * The length of accounts[i] will be in the range [1, 10].
 * The length of accounts[i][j] will be in the range [1, 30].
 * 
 */
class DSU {
public:
    DSU(int n) : p_(n) {
        iota(p_.begin(), p_.end(), 0);
    }

    void Union(const vector<vector<string>> &accounts, int i, int j) {
        if (m_.count(accounts[i][j]))
            p_[Find(i)] = p_[Find(m_[accounts[i][j]])];
        else
            m_[accounts[i][j]] = p_[i];
    }

    unordered_map<int, vector<string>> &Gather() {
        for (auto &it : m_)
            u_[Find(it.second)].push_back(it.first);
        return u_;
    }
private:
    unordered_map<string, int> m_;
    unordered_map<int, vector<string>> u_;
    vector<int> p_;

    int Find(const int a) {
        if (p_[a] != a)
            p_[a] = Find(p_[a]);
        return p_[a];
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        for (int i = 0; i < accounts.size(); ++i)
            for (int j = 1; j < accounts[i].size(); ++j)
                dsu.Union(accounts, i, j);

        auto &m = dsu.Gather();
        vector<vector<string>> result;
        for (auto &it : m) {
            vector<string> &email = it.second;
            sort(email.begin(), email.end());
            email.insert(email.begin(), accounts[it.first][0]);
            result.push_back(email);
        }

        return result;
    }
};
