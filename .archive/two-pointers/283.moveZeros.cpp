#include "../utils.hpp"

using std::swap;

void moveZeroesNOUT(vector<int> &nums) {
  /*
   * Input : vector nums
   * Output: in-place swapping so no output.
   *
   * REASONING:
   * - We use two pointers.
   * - The first pointer c tracks every iteration of the loop (upperbound is
   *   N-1).
   * - The second pointer l does not increment unless the current element c is
   *   non-zero. In other words, if nums[c] != c, we swap nums[c] with nums[l]
   *   and then increment l. Here, we can see that l is a slow moving pointer
   *   that tracks the last non-zero element.
   * - For this algorithm, c is always increasing, and l only increase when a
   *   condition is met. If nums[c] is zero, then l is also guaranteed to be
   *   pointing at a zero.
   */
  for (int l = 0, c = 0; c < nums.size(); ++c) {
    if (nums[c] != 0) {
      swap(nums[l], nums[c]);
      ++l;
    }
  }
}

void moveZeroes(vector<int> &nums) {
  for (int l = 0, c = 0; c < nums.size(); ++c) {
    cout << "for c="<< c << ";\tl=" << l << endl;
    cout << " nums[" << c << "]==" << nums[c] << "; "
         << " nums[" << l << "]==" << nums[l];
    if (nums[c] != 0) {
      cout << "\tswapping" << endl;
      swap(nums[l], nums[c]);
      cout << "\t\t";
      myPrint(nums);
      ++l;
    } else {
      cout << endl << "\t\t";
      myPrint(nums);
    }
    cout << endl;
  }
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> nums = {1, 1, 0, 1, 1, 0, 1};
  myPrint(nums); // before
  cout << endl;
  moveZeroes(nums);
  myPrint(nums); // after
  return 0;
}
