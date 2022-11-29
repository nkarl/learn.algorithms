#include "../utils.hpp"
#include <map>

using std::map;
using std::string;

char findTheDifference(string s, string t) {
    map<char, int> seen;
    for (auto c: s) seen[c] += 1;
    for (auto c: t) {
        if (seen.find(c) == seen.end() || seen[c] == 0)
            return c;
        else
            --seen[c];
    }
    return '\0';
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    string s = "abcd";
    string t = "abcde";
    cout << s << endl;
    cout << t << endl;

    cout << findTheDifference(s, t) << endl;
    return 0;
}
