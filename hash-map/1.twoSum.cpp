#include "../utils.hpp"
#include <map>

using std::map;

vector<int> twoSum(vector<int> &nums, int target) {
  // create a new dictionary to store unique parts.
  map<int, int> dict = {};

  /*
   * Reasoning:
   * - Every element is a possible part of the target, where
   *   the target is composed by exactly two parts at some
   *   index i and j:
   *      target = a + b
   *
   * - Thus, for every p_i=nums[i], go find its other part p_j.
   *    - If p_j not found, insert p_i and i as key-value pair into dict.
   *    - If p_j found, return i and j, where j is and the index saved at dict[p_j].
   */
  for (int i = 0; i < nums.size(); ++i) {
    int a = target - nums[i];
    int b = nums[i];
    if (dict.find(a) == dict.end()) {
      dict[b] = i;
    } else {
      return {dict[a], i};
    }
  }
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
