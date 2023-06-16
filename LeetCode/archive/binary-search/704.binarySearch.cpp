#include "../utils.cpp"
#include <stdint.h>

/*
 * NOTE: Search an already sorted vector.
 *  Time : O(logN)
 *  Space: O(1)
 */
int search(vector<int> &nums, int target) {
    int lo= 0, hi= nums.size() -1;

    while (lo <= hi) {
        int m= lo + (hi - lo) / 2;
        if      (target < nums[m])  hi= m -1;
        else if (target > nums[m])  lo= m +1;
        else                        return m;
    }
    return INT32_MIN;
}

/*
 * NOTE: Recursive search.
 * Time : O(logN)
 *      a == 1 recursive calls
 *      b == 2 sub problems per call
 *      d == 0 extra work done.
 * Space: O(logN)
 */
int searchRecur(vector<int> &nums, int lo, int hi, int target) {
    if (lo > hi)
        return INT32_MIN;

    int m= lo + (hi - lo) / 2;
    if      (target < nums[m])  return searchRecur(nums, lo, m -1, target);
    else if (target > nums[m])  return searchRecur(nums, m +1, hi, target);
    else                        return m;
}

int main(int argc, char *argv[]) {
    vector<int> nums  = {-1, 0, 2, 5, 9, 11};
    int         target= 5;
    myPrint(nums);

    int res   = search(nums, target);
    int res_re= searchRecur(nums, 0, nums.size(), target);
    cout << endl << "key's index, regular search: " << res << endl;
    cout << endl << "key's index, recur   search: " << res_re << endl;

    return 0;
}
