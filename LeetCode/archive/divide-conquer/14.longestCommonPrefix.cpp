/*
 * This is actually advanced stuff. It combines a few different algorithm techniques together.
 */
#include "../utils.hpp"
using std::min;
using std::string;
/*
 * Complexity: O(NlogN) TIme, O(NlogN) Space.
 */

/*
 * Longest Common Prefix. Compares two strings and find the LCP.
 *
 * There are two cases we need to look at:
 *  1. CASE: One string is prefix of the other.
 *      Return the shorter string.
 *
 *  2. CASE: The prefix is substring of both s1 and s2.
 *      Iterate and check every character of the shorter string. If
 *      there is a different char at i, return immediately the prefix.
 *
 */
string getCommonPrefixOf(string s1, string s2) {
    cout << "Enters getCommonPrefixOf(" << s1 << ", " << s2 << ")";
    int shorter = min(s1.length(), s2.length());
    string ret;
    for (int i = 0; i < shorter; ++i) {
        if (s1[i] != s2[i]) {
            cout << " \t-> " << s1.substr(0, i) << endl << endl;
            return s1.substr(0, i);
        }
    }
    cout << " \t-> " << s1.substr(0, shorter) << endl << endl;
    return s1.substr(0, shorter);
}

/*
 * Recursive Form of two pointers using Divide and Conquer.
 *
 * Recurs through two halves of the list of strings and
 * compare element pairwise.
 *
 * We use divide and conquer to break the vector down into chunks
 * of size b==2 small enough for the above method.
 *
 * The algorithm recurs until it hits the base case where the two
 * index pointers are equal, i.e. both pointing to the same string element
 * in the list.
 *
 * T(N) = 2T(N/2) + N
 *  a := 2 recursive calls
 *  b := 2 number of subproblems per recurrence
 *  d := 1 extra linear work (getCommonPrefixOf two strings)
 *  a == b^d --> 2 == 2^1 --> case 1 --> O(NlogN)
 *
 * */
string dfs(vector<string> strs, int lo, int hi, string space, int depth) {
    cout << "Enters dfs, depth=" << depth;
    if (lo == hi) {
         cout << ", base case \t\t-> strs[lo]=" << strs[lo] << endl;
        return strs[lo];
    }

    cout << endl;
    int    m  = lo + (hi - lo) / 2;
    string s1 = dfs(strs, lo, m, space , depth + 1);
    string s2 = dfs(strs, m + 1, hi, space , depth + 1);
    cout << "\t\t" << space << depth << "\t" << s1 << "\tm=" << m << " lo=" << lo << " hi=" << hi << endl;
    cout << "\t\t" << space << depth << "\t" << s2 << endl;
    return getCommonPrefixOf(s1, s2);
}

/*
 * We can use DFS to recur and check each char in both strings.
 *
 * This is a two-step process:
 *  First, how do we compare two strings?
 *      GetCommonPrefix
 *  Second, how do we recur?
 *      DFS or Loop
 *
 * */
string longestCommonPrefix(vector<string> strs) {
    return dfs(strs, 0, strs.size() - 1, "depth=", 0);
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
