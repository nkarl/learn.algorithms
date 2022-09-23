#include "../../utils.hpp"

vector<int>merge(vector<int> &, vector<int> &);
vector<int> merge_sort(vector<int> &, int, int);

vector<int> sortArray(vector<int> &nums) { return nums = merge_sort(nums, 0, nums.size()-1); }

vector<int> merge_sort(vector<int> &nums, int l, int r) {
  if (nums.size() <= 1)
    return nums;

  l = 0; 
  r = nums.size() - 1;
  auto m = l + (l+r)/2;
  vector<int> left(nums.begin(), nums.begin()+m);
  myPrint(left);
  left = merge_sort(left, l, m);
  vector<int> right(nums.begin()+m+1, nums.begin()+r);
  myPrint(right);
  right = merge_sort(right, m+1, r);
  return merge(left, right);
}

vector<int> merge(vector<int> &left, vector<int> &right) {
  int l = 0;
  int r = 0;
  vector<int> ret = {};
  while (l < left.size() && r < right.size()) {
    if (left[l] < right[r]) {
      ret.push_back(left[l]);
      ++l;
    } else {
      ret.push_back(right[r]);
      ++r;
    }
  }

  for (; l < left.size(); ++l)
    ret.push_back(left[l]);
  for (; r < right.size(); ++r)
    ret.push_back(left[r]);
  return ret;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> nums = {5, 4, 3, 2, 1};
  myPrint(nums); // before
  auto c = sortArray(nums);
  myPrint(c); // after
  return 0;
}
