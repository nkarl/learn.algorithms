#include "../utils.hpp"
using std::min; using std::string;

/*
 * Complexity: O(NlogN) Time, O(1) Space.
 */

/**
 * Check if there is a common prefix at a given length.
 */
bool isCommonPrefix(vector<string> &strs, int len) {
    string prefix = strs[0].substr(0, len); // get the prefix.
    // Confirms that every string in the vector has the prefix at given length.
    for (int i=1; i < strs.size(); ++i) {
        if (!(strs[i].find(prefix) == 0)) // can't be prefix if not starts at 0.
            return false;
    }
    return true;
}

/**
 * Public interface that takes a vector of strings.
 */
string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return "";    // base case.
    // Find the shortest in the vector to use as the limit of prefix.
    int shortest = strs[0].size();
    for (auto str : strs) {
        shortest = min(shortest, (int)str.size());
    }

    // Find the terminating index of common prefix.
    int lo = 1; int hi = shortest;
    while (lo <= hi) {
        int m = lo+(hi-lo)/2;
        if (isCommonPrefix(strs, m)) lo = m+1;
        else                         hi = m-1;
    }
    return strs[0].substr(0, (hi+lo)/2);
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
