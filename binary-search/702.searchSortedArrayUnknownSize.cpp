#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class ArrayReader {
public:
  vector<int> *vec = nullptr;
  ArrayReader(vector<int> &nums) { this->vec = &nums; }
  int get(int index) {
    if (index < vec->size()) {
      return (*vec)[index];
    } else {
      return INT32_MAX;
    }
  };
};

/*
 * NOTE: Search in logarithmic time, assuming that the
 *  vector is already sorted.
 */
int search(ArrayReader &reader, int target) {
    int lo=0; int hi=1;

    // establish the bounds
    while (reader.get(hi) < target) {
        lo = hi;
        hi *= 2;
    }
    cout << lo << " " << hi << endl;

    // binary search core
    while (lo <= hi) {
        int m = lo + ((hi - lo) / 2);
        int num = reader.get(m);
        if      (target < num) hi = m-1;
        else if (target > num) lo = m+1;
        else    return m;
    }

    return -1;
}

int main(int argc, char *argv[]) {

  vector<int> nums = {-1, 0, 2, 5, 9, 11};
  // vector<int> nums = { -1, 0, 3, 5, 9, 12 };
  int target = 5;

  ArrayReader reader(nums);

  for (auto i : *(reader.vec)) {
    cout << i << ' ';
  }

  int res = search(reader, target);
  //int res_re = recurSearch(nums, 0, nums.size() - 1, target);
  cout << endl << "index of target: " << res << endl;
  //cout << endl << "target index:" << res_re << endl;

  return 0;
}
