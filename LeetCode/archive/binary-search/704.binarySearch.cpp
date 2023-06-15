#include <stdint.h>
#include "../utils.cpp"

/*
 * NOTE: Search an already sorted vector.
 *  Time: O(NlogN)
 */
int search(vector<int> &nums, int target) {
    int lo  = 0, hi=nums.size()-1;

    while (lo <= hi) {
        int m = lo+(hi-lo)/2;
        if      (target < nums[m]) hi=m-1;
        else if (target > nums[m]) lo=m+1;
        else    return m;
    }
    return INT32_MIN;
}

/*
 * NOTE: Recursive search.
 * Time: O(NlogN)
 * Space: O(NlogN)
 */
int searchRecur(vector<int> &nums, int lo, int hi, int target) {
    if (lo > hi) return INT32_MIN;

    int m = lo+(hi-lo)/2;
    if      (target < nums[m])  return searchRecur(nums, target, lo, m-1);
    else if (target > nums[m])  return searchRecur(nums, target, m+1, hi);
    else                        return m;
}

int main(int argc, char *argv[]) {

    vector<int> nums = {-1, 0, 2, 5, 9, 11};
    // vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int target = 5;
    myPrint(nums);

    int res    = search(nums, target);
    int res_re = searchRecur(nums, 0, nums.size(), target);
    cout << endl << "key's index, regular search: " << res    << endl;
    cout << endl << "key's index, recur   search: " << res_re << endl;

    return 0;
}
