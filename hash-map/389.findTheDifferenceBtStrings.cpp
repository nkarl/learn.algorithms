#include "../utils.hpp"
#include <map>

using std::map;
using std::string;

char findTheDifference(string s, string t) {
    map<char, int> chars = {};
    for (char c : s) {
        ++chars[c];
    }

    for (auto e : chars) {
        cout << "K=" << e.first << " V=" << e.second << "; ";
    }
    cout << endl;

    char ex = '\0';
    for (char c : t) {
        if ((chars.find(c) == chars.end()) || chars[c] == 0)
            return c;
        else
            --chars[c];
    }
    return ex;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    string s = "abcd";
    string t = "abcde";

    cout << findTheDifference(s, t) << endl;
    return 0;
}
