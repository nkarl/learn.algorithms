#include "../utils.hpp"
#include <map>

using std::map;

vector<int> twoSum(vector<int> &nums, int target) {
  /*
   * Input : vector nums; a target integer.
   * Output: the pair of indices of the elements summing up to target.
   *
   * Reasoning:
   * - The vector may contain exactly two elements that compose the target.
   * - Every element is a possible part of a 2-set.
   * - If there exists a solution set, then the target is composed of exactly
   *   two parts in [a, x] where:
   *
   *        target = a + x
   *
   * - Thus, for every a=nums[i], go find its other part x.
   *    - If x is NOT FOUND, then we know that a is part of a new solution set,
   *      and thus, we save a and its index i for future lookup.
   *    - Otherwise x FOUND, then we simply return the index of the saved part
   *      and the index at i.
   *    - If no solution set is found, return an empty vector.
   */

  // create a new dictionary to memoize possible parts.
  map<int, int> dict = {};

  // start looking for parts a and b.
  for (int i = 0; i < nums.size(); ++i) {
    int a = nums[i];
    int x = target - a;
    if (dict.find(x) == dict.end()) {
      dict[a] = i;
    } else {
      return {i, dict[x]};
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
