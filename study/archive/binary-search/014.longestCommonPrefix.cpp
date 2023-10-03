#include "../utils.cpp"
using std::min; using std::string;

/**
 * Check that every string in the vector contains a prefix of length m.
 */
bool isCommonPrefix(vector<string> &strs, int m) {
    string prefix= strs[0].substr(0, m);
    for (auto s : strs) {
        if (s.find(prefix) != 0) return false;
    }
    return true;
}

string findCommonPrefix(vector<string> &strs, int lo, int hi) {
    if (lo > hi) {
        return strs[0].substr(0, hi);
    }
    int mid= lo + (hi - lo) / 2;
    if (isCommonPrefix(strs, mid))  return findCommonPrefix(strs, mid+1, hi);
    else                            return findCommonPrefix(strs, lo, mid-1);
}

/*
 * Longest Common Prefix.
 * Complexity: O(NlogN) Time. O(1) Space on loop, O(NlogN) Space on recursion.
 */
string longestCommonPrefix(vector<string> &strs) {
    /*
     * First, find the shortest string in vector.
     */
    int shortest= strs[0].size();
    for (auto s : strs) {
        shortest= min(shortest, (int)s.size());
    }

    /*
     * Given the size of the shortest string, we use binary search to find the
     * longest common prefix on the length of the shortest.
     * If the common prefix is shorter than mid, we can eliminate the right half
     * of the shortest.
     */
    return findCommonPrefix(strs, 0, shortest);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<string> vec1  = {"flow", "flower", "flight"};
    vector<string> vec2  = {"aaaa", "aaab", "aaac", "aabc"};
    vector<string> strs  = vec2;
    string         prefix= longestCommonPrefix(strs);
    printf("prefix = %s\n", prefix.c_str());
    return 0;
}
