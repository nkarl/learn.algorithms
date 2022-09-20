#include "../utils.hpp"
#include <map>
using std::map;

vector<int> twoSum(vector<int> &nums, int target) {
  map<int, int> seen = {};
  for (int i = 0; i < nums.size(); i++) {
    int candidate = nums[i];
    if (seen.find(candidate) != seen.end()) {
      return {seen[candidate], i};
    }
    else {
        seen[target - candidate] = i;
    }
  }
  // In case there is no solution, we'll just return empty vector.
  return {};
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  myPrint(nums); // before
  auto c = twoSum(nums, 7);
  myPrint(nums); // after
  myPrint(c);
  return 0;
}
