#include "../utils.hpp"
#include <map>
using std::map;

vector<int> twoSum(vector<int> &nums, int target) {
  /*
   * Could be a greedy algorithm here. But it is a good chance to
   * practice dynamic programming here.
   */
  // auto ret = new vector<int>();
  map<int, int> seen = {};
  for (int i = 0; i < nums.size(); i++) {
    if (seen.find(nums[i]) != seen.end()) {
      return {i, seen[nums[i]]};
    }
    else {
        seen[target - nums[i]] = i;
    }
  }
  // In case there is no solution, we'll just return null
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
