class Solution {
public:
    bool isPrefix(vector<string> &strs, int m) {
        string prefix = strs[0].substr(0, m);
        for (auto s: strs) {
            if (s.find(prefix) != 0) return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        /*
         * Find the shortest string in the vector.
         */
        int shortest = strs[0].size();
        for (auto s: strs)
            shortest = min(shortest, (int)s.size());

        /*
         * Use binary search
         */
        int lo=0; int hi=shortest;
        while (lo <= hi) {
            int m=lo+(hi-lo)/2;
            if (isPrefix(strs, m)) lo=m+1;
            else                   hi=m-1;
        }
        return strs[0].substr(0, (lo+hi)/2);
    }
};
