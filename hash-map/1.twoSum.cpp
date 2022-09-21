#include "../utils.hpp"
#include <map>

using std::map;

vector<int> twoSum(vector<int> &nums, int target) {

  map<int, int> seen = {}; // Creates a new dictionary.

  for (int i = 0; i < nums.size(); i++) {
    auto candidate = nums[i];
    auto diff = target - candidate;

    // Find diff.
    //  if not found, add candidate and its index to dictionary.
    if (seen.find(diff) == seen.end()) {
      seen[candidate] = i;
      cout << "NOT FOUND:" << endl;
      for (auto i : seen) {
        cout << "\t\tkey: diff=" << i.first << "\tval: i=" << i.second << endl;
      }
    }
    //  if found, return indices of both diff and candidate.
    else {
      return {seen[diff], i};
    }
  }
  // In case there is no solution, we'll just return empty vector.
  return {};
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 0, 0, 5, 6};
  myPrint(nums); // before
  auto c = twoSum(nums, 7);
  myPrint(nums); // after
  myPrint(c);
  return 0;
}
