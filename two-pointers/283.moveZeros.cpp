#include "../utils.hpp"

using std::swap;

void moveZeroes(vector<int> &nums) {
  for (int l = 0, c = 0; c < nums.size(); ++c) {
    cout << "for="  << c << ";l=" << l << endl;
    cout << "nums[" << c << "]==" << nums[c] << "; "
         << "nums[" << l << "]==" << nums[l];
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
  vector<int> nums = {1, 0, 2, 0, 3};
  myPrint(nums); // before
  moveZeroes(nums);
  myPrint(nums); // after
  return 0;
}
