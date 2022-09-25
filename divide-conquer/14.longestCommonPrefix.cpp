#include "../utils.hpp"

using std::min;
using std::string;

string commonPrefix(string left, string right) {
    int shortest = min(left.length(), right.length());
    for (int i = 0; i < shortest; i++) {
        if (left[i] != right[i])
            return left.substr(0, i);
    }
    return left.substr(0, shortest);
}

string longestCommonPrefix(vector<string> &strs, int l, int r) {
    if (l == r) {
        return strs[l];
    }
    else {
        int    m        = (l + r) / 2;
        string lcpLeft  = longestCommonPrefix(strs, l, m);
        string lcpRight = longestCommonPrefix(strs, m + 1, r);
        return commonPrefix(lcpLeft, lcpRight);
    }
}

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return "";
    return longestCommonPrefix(strs, 0, strs.size() - 1);
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
