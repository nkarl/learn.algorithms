#include "../utils.hpp"

using std::min;
using std::string;

bool isCommonPrefix(vector<string> &strs, int len) {
    string prefix = strs[0].substr(0, len);  // get the prefix.

    /*
     * Checks all strings in the vector if each and everyone has the prefix.
     */
    for (int i = 1; i < strs.size(); ++i) {
        if (!(strs[i].find(prefix) == 0)) return false;  // if doesn't start at 0.
    }
    return true;
}

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return "";

    /*
     * Find the shortest string in the vector and use its size as the minimum length.
     */
    int shortest = strs[0].size();
    for (auto str : strs) {
        shortest = min(shortest, (int)str.size());
    }

    /*
     * we apply binary search for the end index of the common prefix (if exists).
     */
    int lo = 1; int hi = shortest;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (isCommonPrefix(strs, m))
            lo = m + 1;
        else
            hi = m - 1;
    }
    return strs[0].substr(0, (hi + lo) / 2);
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
