#include "../utils.hpp"

using std::swap;

void moveZeroes(vector<int> &nums) {
  for (int last = 0, curr = 0; curr < nums.size(); ++curr) {
    cout << "for=" << curr << "; last=" << last << endl;
    if (nums[curr] != 0) {
      cout << "nums[" << last << "]=" << nums[last]
         << "; "
         << "nums[" << curr << "]=" << nums[curr] << endl;
      swap(nums[last], nums[curr]);
      ++last;
    }
    myPrint(nums);
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
