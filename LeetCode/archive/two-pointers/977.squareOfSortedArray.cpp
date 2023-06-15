#include "../utils.cpp"

/**
 *  This approach does not rely on an external library for sorting.
 *  With one single O(N) loop, the array is both mapped and sorted.
 *
 *  Description:
 *      movement: bidirectional, simultanous.
 *
 *  Complexity:
 *      O(N) time
 *      O(N) space
 */
vector<int> sortedSquares(vector<int> &nums) {
    vector<int> res(nums.size());
    int N = nums.size();

    int l=0; int r=N-1; int sq;
    for (int i=0; i<N; ++i) {
        if (abs(nums[l]) < abs(nums[r])) sq = nums[r--];
        else                             sq = nums[l++];
        res[N-1-i] = sq * sq;
    }
    return res;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<int> nums = {-4, -1, 0, 3, 10};
    myPrint(nums);  // before
    nums = sortedSquares(nums);
    myPrint(nums);  // after
    return 0;
}
