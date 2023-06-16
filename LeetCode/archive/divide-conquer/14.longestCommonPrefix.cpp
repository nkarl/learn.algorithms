/*
 * This is actually advanced stuff. It combines a few different algorithm techniques together.
 */
#include "../utils.cpp"
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
 * Complexity:
 *  Time : O(N)
 *  Space: O(1)
 */
string getCommonPrefixOf(string s1, string s2, string indent) {
    printf("%s...........\n", indent.c_str());
    printf("%s > getCommonPrefixOf(%s, %s)", indent.c_str(), s1.c_str(), s2.c_str());

    int shorter= min(s1.length(), s2.length());

    for (int i= 0; i < shorter; ++i) {
        if (s1[i] != s2[i]) {
            printf(" --> %s\n\n", s1.substr(0, i).c_str());
            return s1.substr(0, i);
        }
    }
    printf(" --> %s\n", s1.substr(0, shorter).c_str());
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
    string indent = "\t";
    for (auto i=0; i < depth; ++i)
        indent += "\t";
    printf("%s-----------\n", indent.c_str());
    printf("%s > dfs()\n%s   depth=%d", indent.c_str(), indent.c_str(), depth);
    printf(", lo=%d m=%d hi=%d", lo, lo + (hi-lo)/2, hi);
    if (lo == hi) {
        printf(", base case --> strs[%d]=%s\n", lo, strs[lo].c_str());
        return strs[lo];
    }

    //printf("\n");
    int    m = lo + (hi - lo) / 2;
    //printf(" m=%d\n", m);
    printf("\n");
    string s1= dfs(strs, lo, m, space, depth + 1);
    printf("%s   s1=%s\n", indent.c_str(), s1.c_str());
    string s2= dfs(strs, m + 1, hi, space, depth + 1);
    printf("%s   s2=%s\n", indent.c_str(), s2.c_str());
    //printf("%s%s%d\t%s\tm=%d lo=%d hi=%d\n", indent.c_str(), space.c_str(), depth, s1.c_str(), m, lo, hi);
    //printf("%s%s%d\t%s\n", indent.c_str(), space.c_str(), depth, s2.c_str());
    return getCommonPrefixOf(s1, s2, indent);
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
    printf("\n > LCP()\n");
    return dfs(strs, 0, strs.size() - 1, "depth=", 0);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<string> vec1  = {"flow", "flower", "flight"};
    vector<string> vec2  = {"aaaa", "aaab", "aaac", "aabc"};
    vector<string> vec3  = {"aaaa", "aaab", "aaac", "aabc", "aaaaaabc", "aaaaacdb", };
    vector<string> vec4  = {"aaaa", "aaab", "aaac", "aabc", "aaaaaabc", "aaaaacdb", "aaaaabcde", "aaaaecdg" };
    vector<string> strs  = vec2;
    myPrint(strs);
    string         prefix= longestCommonPrefix(strs);
    printf("\n > prefix = %s\n", prefix.c_str());
    return 0;
}
