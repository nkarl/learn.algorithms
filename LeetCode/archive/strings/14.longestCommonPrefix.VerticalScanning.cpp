#include "../utils.hpp"

using std::string;

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return "";
    string prefix = strs[0];
    for (int i = 0; i < prefix.length() ; i++){
        char c = prefix[i];
        for (int j = 1; j < strs.size() ; j ++) {
            if (i == strs[j].length() || strs[j][i] != c)
                return prefix.substr(0, i);             
        }
    }
    return prefix;
}
/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<string> strs = {"flow", "flower", "flight"};
    string prefix = longestCommonPrefix(strs);
    cout << prefix << endl;
    return 0;
}
