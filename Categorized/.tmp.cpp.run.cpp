
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

/// leetcode defined data types ///
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* make_listnode(const vector<int> &v) {
  ListNode head(0), *p = &head, *cur;
  for (auto x: v) { cur = new ListNode(x); p->next = cur; p = cur; }
  return head.next;
}

constexpr long long null = numeric_limits<long long>::min();

TreeNode* make_treenode(const vector<long long> &v) {
  vector<TreeNode*> cur, next;
  TreeNode root(0); cur.push_back(&root);
  long long i = 0, n = v.size(), x;
  while (i < n) {
    for (auto p: cur) {
      if ((x = v[i++]) != null) { p->left = new TreeNode(x); next.push_back(p->left); }
      if (i == n || p == &root) continue;
      if ((x = v[i++]) != null) { p->right = new TreeNode(x); next.push_back(p->right); }
    }
    cur.swap(next); next.clear();
  }
  return root.left;
}

template<class T>
ostream& operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) os << (i > 0 ? "," : "") << v[i];
  os << "]";
  return os;
}

ostream& operator<<(ostream &os, const ListNode *p) {
  vector<int> v;
  while (p) { v.push_back(p->val); p = p->next; }
  return os << v;
}

ostream& operator<<(ostream &os, const TreeNode *t) {
  vector<string> v;
  queue<const TreeNode*> cur, next;
  if (t) cur.push(t);

  while (!cur.empty()) {
    t = cur.front(); cur.pop();
    v.push_back(t ? to_string(t->val) : "null");
    if (t && (t->left || t->right)) {
      next.push(t->left);
      if (t->right || !cur.empty()) next.push(t->right);
    }
    if (cur.empty()) cur.swap(next);
  }
  return os << v;
}

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (49.33%)
 * Total Accepted:    366.8K
 * Total Submissions: 739.6K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> result;
        dfs(candidates, target, 0, 0, cur, result);
        return result;
    }
private:
    void dfs(const vector<int> nums,
             int target,
             int lastElem, int curSum, vector<int> &cur, vector<vector<int>>& result) {
        if ( curSum > target)
            return;
        if (curSum == target) {
            result.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < lastElem)
                continue;
            cur.push_back(nums[i]);
            dfs(nums, target, nums[i], curSum + nums[i], cur, result);
            cur.pop_back();
        }
        return;
    }
};

int main() {
  Solution s;
  decay<vector<int>&>::type p0 = {2,3,6,7};
  decay<int>::type p1 = 7;
  auto res = s.combinationSum(p0,p1);
  cout << res << endl;
  return 0;
}
