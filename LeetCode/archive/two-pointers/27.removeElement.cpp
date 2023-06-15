#include "../utils.cpp"

using std::swap;

int removeElement(vector<int> &nums, int val) {
  int k=0;
  for (int l = 0, c = 0; c < nums.size(); ++c) {
    cout << "for=" << c << "; l=" << l << endl;
    cout << "nums[" << c << "]==" << nums[c] << "; "
         << "nums[" << l << "]==" << nums[l];
    if (nums[c] != val) {
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
    k = l;
  }
  return nums.size() - (nums.size() - k);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> nums = {1, 0, 2, 0, 3};
  int val = 3;
  myPrint(nums); // before
  int c = removeElement(nums, val);
  myPrint(nums); // after
  for (int i=0; i < c; ++i) {
      cout << nums[i] << ' ';
  }
  cout << endl;
  return 0;
}
