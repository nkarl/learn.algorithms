#include "../utils.cpp"
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
    printf("%s\n", s.c_str());
    printf("%s\n", t.c_str());

    printf("%c\n", findTheDifference(s, t));
    return 0;
}
