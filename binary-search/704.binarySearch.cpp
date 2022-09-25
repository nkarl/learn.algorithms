#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
 * NOTE: Search in logarithmic time, assuming that the
 *  vector is already sorted.
 */
int search(vector<int> &nums, int target) {
  int key = target;
  int lo = 0, hi = nums.size() - 1;

  while (lo <= hi) {
    int m = lo + (hi - lo) / 2;

    if      (key < nums[m]) hi = m - 1;
    else if (key > nums[m]) lo = m + 1;
    else                    return m;
  }
  return -1;
}

/*
 * Recursive implementation of search.
 */
int recurSearch(vector<int> &nums, int target, int lo, int hi) {
  if (lo > hi) return -1;

  int m = lo + (hi - lo) / 2;
  if      (target < nums[m]) return recurSearch(nums, target, lo, m - 1);
  else if (target > nums[m]) return recurSearch(nums, target, m + 1, hi);
  else                       return m;
}

int main(int argc, char *argv[]) {

  vector<int> nums = {-1, 0, 2, 5, 9, 11};
  // vector<int> nums = { -1, 0, 3, 5, 9, 12 };
  int key = 5;

  for (auto i : nums) {
    cout << i << ' ';
  }

  int res = search(nums, key);
  int res_re = recurSearch(nums, 0, nums.size() - 1, key);
  cout << endl << "key index:" << res << endl;
  cout << endl << "key index:" << res_re << endl;

  return 0;
}