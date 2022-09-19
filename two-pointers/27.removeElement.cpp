#include "../utils.hpp"

using std::swap;

int moveZeroes(vector<int> &nums, int val) {
  int ll=0;
  for (int last = 0, curr = 0; curr < nums.size(); ++curr) {
    cout << "for=" << curr << "; last=" << last << endl;
    cout << "nums[" << curr << "]==" << nums[curr] << "; "
         << "nums[" << last << "]==" << nums[last];
    if (nums[curr] != val) {
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
    ll = last;
  }
  return nums.size() - (nums.size() - ll);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> nums = {1, 0, 2, 0, 3};
  int val = 3;
  myPrint(nums); // before
  int c = moveZeroes(nums, val);
  myPrint(nums); // after
  for (int i=0; i < c; ++i) {
      cout << nums[i] << ' ';
  }
  cout << endl;
  return 0;
}
