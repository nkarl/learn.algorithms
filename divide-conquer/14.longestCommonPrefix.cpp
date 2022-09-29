#include "../utils.hpp"
using std::min; using std::string;

/*
 * Complexity: O(N) Time, O(N) Space.
 */

/**
 * Finds the common prefix (substring) of two strings.
 */
string commonPrefix(string left, string right) {
    int shortest = min(left.size(), right.size());
    for (int i=0; i < shortest; i++) {
        if (left[i] != right[i]) return left.substr(0, i);
    }
    return left.substr(0, shortest);
}

/**
 * Find the longest common prefix from a vector of strings.
 */
string dfs(vector<string> &strs, int l, int r) {
    if (l == r) return strs[l];     // base case.
    else {
        int    m        = (l + r) / 2;
        string lcpLeft  = dfs(strs, l, m);
        string lcpRight = dfs(strs, m + 1, r);
        return commonPrefix(lcpLeft, lcpRight);
    }
}

/**
 * Public interface that takes a vector of strings.
 */
string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return "";
    return dfs(strs, 0, strs.size() - 1);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<string> strs   = {"flow", "flower", "flight"};
    string         prefix = longestCommonPrefix(strs);
    cout << prefix << endl;
    return 0;
}
