#include "../utils.hpp"
using std::min; using std::string;

/*
 * Complexity: O(NlogN) Time, O(1) Space.
 */

/**
 * Check that every string in the vector contains a prefix of length m.
 */
bool isCommonPrefix(vector<string> &strs, int m) {
    string prefix = strs[0].substr(0, m);
    for (auto s: strs) {
        if (s.find(prefix) != 0) return false;
    }
    return true;
}

/*
 * Longest Common Prefix.
 */
string longestCommonPrefix(vector<string> &strs) {
    /*
     * First, find the shortest string in vector.
     */
    int shortest = strs[0].size();
    for (auto s: strs) {
        shortest = min(shortest, (int)s.size());
    }

    /*
     * Given the size of the shortest string, we use binary search to find the
     * longest common prefix on the length of the shortest.
     * If the common prefix is shorter than mid, we can eliminate the right half
     * of the shortest.
     */
    int lo = 0; int hi = shortest; int m;
    while (lo <= hi) {
        m = lo+(hi-lo)/2;
        if (isCommonPrefix(strs, m)) lo=m+1;
        else                         hi=m-1;
    }
    return strs[0].substr(0, lo-1);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<string> vec1 = {"flow", "flower", "flight"};
    vector<string> vec2 = {"aaaa", "aaab", "aaac", "aabc"};
    vector<string> strs = vec2;
    string         prefix = longestCommonPrefix(strs);
    cout << prefix << endl;
    return 0;
}
