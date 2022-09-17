#include "../utils.hpp"

using std::swap;

void moveZeroes(vector<int> &nums) {
  for (int last = 0, curr = 0; curr < nums.size(); ++curr) {
    cout << "for=" << curr << "; last=" << last << endl;
    cout << "nums[" << curr << "]==" << nums[curr] << "; "
         << "nums[" << last << "]==" << nums[last];
    if (nums[curr] != 0) {
      cout << "\tswapping" << endl;
      swap(nums[last], nums[curr]);
      cout << "\t\t";
      myPrint(nums);
      ++last;
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
