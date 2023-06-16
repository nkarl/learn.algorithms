#include "../utils.cpp"

class ArrayReader {
  public:
    vector<int> *vec = nullptr;
    ArrayReader(vector<int> &nums) : vec{&nums} {}
    int get(int i) {
        if (i < vec->size())
            return (*vec)[i];
        else
            return INT32_MAX;
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
        lo = hi; hi *= 2;
    }
    printf("%d %d\n", lo, hi);

    // binary search core
    while (lo <= hi) {
        int m   = lo+(hi-lo)/2;
        int num = reader.get(m);
        if      (target < num) hi=m-1;
        else if (target > num) lo=m+1;
        else    return m;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    vector<int> nums = {-1, 0, 2, 5, 9, 11};
    int         target = 5;
    ArrayReader reader(nums);
    myPrint(*(reader.vec));

    int res = search(reader, target);
    // int res_re = recurSearch(nums, 0, nums.size()-1, target);
    printf("\nindex of target: %d\n", res);
    return 0;
}
