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
 *  2. CASE: The prefix is substring of both a and b.
 *      Iterate and check every character of the shorter string. If
 *      there is a different char at i, return immediately the prefix.
 *
 * Complexity:
 *  Time : O(N)
 *  Space: O(1)
 */
string getCommonPrefixOf(string a, string b) { //, string indent) {
    //printf("%s...........\n", indent.c_str());
    //printf("%s > getCommonPrefixOf(%s, %s)", indent.c_str(), a.c_str(), b.c_str());

    int shorter= min(a.length(), b.length());

    for (int i= 0; i < shorter; ++i) {
        if (a[i] != b[i]) {
            //printf(" --> %s\n\n", a.substr(0, i).c_str());
            return a.substr(0, i);
        }
    }
    //printf(" --> %s\n", a.substr(0, shorter).c_str());
    return a.substr(0, shorter);
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
string divideConquer(vector<string> strs, int lo, int hi) { //, int depth, string space) {
    //string indent = "\t";
    //for (auto i=0; i < depth; ++i)
        //indent += "\t";
    //printf("%s-----------\n", indent.c_str());
    //printf("%s > dfs() depth=%d", indent.c_str(), depth);
    //printf(" lo=%d m=%d hi=%d", lo, lo + (hi-lo)/2, hi);
    if (lo == hi) {
        //printf(", base case --> strs[%d]=%s\n", lo, strs[lo].c_str());
        return strs[lo];
    }

    //printf("\n");
    int  mid= lo +(hi -lo) /2;
    //printf(" m=%d\n", m);
    //printf("\n");
    string a= divideConquer(strs, lo    , mid); //, depth +1, space);
    //printf("%s   a=%s\n", indent.c_str(), a.c_str());
    string b= divideConquer(strs, mid +1,  hi); //, depth +1, space);
    //printf("%s   b=%s\n", indent.c_str(), b.c_str());
    //printf("%s%s%d\t%s\tm=%d lo=%d hi=%d\n", indent.c_str(), space.c_str(), depth, a.c_str(), m, lo, hi);
    //printf("%s%s%d\t%s\n", indent.c_str(), space.c_str(), depth, b.c_str());
    return getCommonPrefixOf(a, b); //, indent);
}

/*
 * We can use divide-and-conquer to recur and check each char in both strings.
 *
 * This is a two-step process:
 *  First, how do we compare two strings?
 *      GetCommonPrefix
 *  Second, how do we recur?
 *      DFS or Loop
 *
 * */
string longestCommonPrefix(vector<string> strs) {
    //printf("\n > LCP()\n");
    return divideConquer(strs, 0, strs.size() - 1); //, 0, "depth=");
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<string> vec1  = {"flow", "flower", "flight"};
    vector<string> vec2  = {"aaaa", "aaab", "aaac", "aabc"};
    vector<string> vec3  = {"aaaa", "aaab", "aaac", "aabc", "aaaaaabc", "aaaaacdb", };
    vector<string> vec4  = {"aaaa", "aaab", "aaac", "aabc", "aaaaaabc", "aaaaacdb", "aaaaabcde", "aaaaecdg" };
    vector<string> strs  = vec4;
    myPrint(strs);
    string         prefix= longestCommonPrefix(strs);
    printf("\n > prefix = %s\n", prefix.c_str());
    return 0;
}
