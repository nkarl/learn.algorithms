#include "../utils.hpp"
#include <map>

using std::map;

vector<int> twoSum(vector<int> &nums, int target) {

  map<int, int> dict = {}; // Creates a new dictionary.

  for (int i = 0; i < nums.size(); i++) {
    /*
     * Let candidate be element at i.
     */
    int candidate = nums[i];

    /*
     * Binary check if the candidate is already in <dict>.
     */
    if (dict.find(candidate) == dict.end()) {
      /*
       * If true, memorizes the difference (target - candidate) into
       * the dictionary with i as value.
       */
      dict[target - candidate] = i;
    } else {
      /*
       * Otherwise, returns a 2-vector of the candiate and i right away. (the
       * two elements summing up to target)
       */
      return {dict[candidate], i};
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
