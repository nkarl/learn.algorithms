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
   * - Every element is a possible part of an unordered solution pair.
   * - If there exists a solution set, then the target is composed of exactly
   *   two parts in {a_x, b_i} at some unique indices x and i:
   *
   *        target = a_x + b_i
   *
   * - Thus, for every b=nums[i], go find its other part a.
   *    - If a is NOT FOUND, then we know that b is part of a new solution set.
   *      Thus, we immediately insert b and i as a new key-value pair into dict
   *      for future lookup.
   *    - Otherwise a FOUND, then we have both x and i. The solution is the
   *      index x saved at dict[a] and i. Thus we return immediately a new
   *      2-vector {dict[a], i}.
   *
   * - If no solution set is found, return an empty vector.
   */

  // create a new dictionary to memoize possible parts.
  map<int, int> dict = {};

  // start looking for parts a and b.
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
