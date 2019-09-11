/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (51.99%)
 * Total Accepted:    29.4K
 * Total Submissions: 56.3K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * 
 * Implement a MapSum class with insert, and sum methods.
 * 
 * 
 * 
 * For the method insert, you'll be given a pair of (string, integer). The
 * string represents the key and the integer represents the value. If the key
 * already existed, then the original key-value pair will be overridden to the
 * new one.
 * 
 * 
 * 
 * For the method sum, you'll be given a string representing the prefix, and
 * you need to return the sum of all the pairs' value whose key starts with the
 * prefix.
 * 
 * 
 * Example 1:
 * 
 * Input: insert("apple", 3), Output: Null
 * Input: sum("ap"), Output: 3
 * Input: insert("app", 2), Output: Null
 * Input: sum("ap"), Output: 5
 * 
 * 
 * 
 */
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() : root(new TreeNode()){
        
    }
    
    void insert(string key, int val) {
        auto p = root.get();
        for (char ch : key) {
            if (p->children[ch-'a'] == nullptr) 
                p->children[ch-'a'] = new TreeNode();
            p = p->children[ch-'a'];
            p->sum += val;
        }
        if (p->val) {
            int oldkey = *(p->val);
            *(p->val) = val;
            p = root.get();
            for (char ch : key) {
                p = p->children[ch-'a'];
                p->sum -= oldkey;
            }
        }
        else
            p->val = new int(val);
    }
    
    int sum(string prefix) {
        auto p = root.get();
        for (char ch : prefix) {
            p = p->children[ch-'a'];
            if (p == nullptr)
                break;
        }
        return p ? p->sum : 0;
    }
private:
    struct TreeNode {
        int sum;
        int *val;
        vector<TreeNode *> children;
        TreeNode() : sum(0), val(nullptr), children(26, nullptr) {}
        ~TreeNode() {
            if (val)
                delete val;
            for (auto child : children)
                if (child)
                    child->~TreeNode();
        }
    };
    unique_ptr<TreeNode> root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
