#include "../utils.hpp"
using std::min;
using std::string;

/*
 * Complexity: O(NlogN) TIme, O(NlogN) Space.
 */

/*
 * Longest Common Prefix.
 */
string getCommonPrefixOf(string s1, string s2) {
    /*
     * There are two cases we need to look at:
     *  1. either one is a prefix of the other. In this case we simply
     *      return the substring as the range from 0 to the shorter
     *      string.
     *
     *  2. The other case is when the prefix is shorter than both s1 and s2.
     *      In this case we must iterate and check every character from 0
     *      to the shorter value. If there is a different char at i, we
     *      can return the prefix immediately.
     */
    int shorter = min(s1.length(), s2.length());
    for (int i = 0; i < shorter; ++i) {
        if (s1[i] != s2[i]) return s1.substr(0, i);
    }
    return s1.substr(0, shorter);
}

string dfs(vector<string> strs, int lo, int hi) {
    /*
     * Assuming the vector contains only two strings. We compare them
     * directly.
     *
     * Now what do we do when the size of vector > 2?
     *
     * We use divide and conquer to break the vector down into chunks
     * small enough for the above method.
     *
     * Notice that the rank of the vector is just an array of indices.
     * We can use something similar to binary search to push pairwise
     * elements onto the stack and then apply the function above to
     * solve recursively.
     *
     * We can use DFS since it uses an implicit stack via recursion,
     * meaning we don't need to worry about keeping a stack ourselves.
     *
     * We also need a base case to terminate the recursive calls.
     */
    if (lo == hi)
        return strs[lo];

    int    m  = lo + (hi - lo) / 2;
    string s1 = dfs(strs, lo, m);
    string s2 = dfs(strs, m + 1, hi);

    return getCommonPrefixOf(s1, s2);
}

string longestCommonPrefix(vector<string> strs) {
    return dfs(strs, 0, strs.size() - 1);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<string> vec1   = {"flow", "flower", "flight"};
    vector<string> vec2   = {"aaaa", "aaab", "aaac", "aabc"};
    vector<string> strs   = vec2;
    string         prefix = longestCommonPrefix(strs);
    cout << prefix << endl;
    return 0;
}
