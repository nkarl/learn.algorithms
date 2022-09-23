#include "../utils.hpp"

/*
 * Rotates k elements at the tail to the front of an array.
 *  Input:
 *      [1,2,3,4,5,6,7]
 *      k = 3
 *  Output:
 *      [5,6,7,1,2,3,4]
 *
 *  Description:
 *      movement: isodirectional, stepwise.
 *
 *  Complexity:
 *      O(N) time
 *      O(1) space
 */
void rotate(vector<int> &nums, int k) {
    int N = nums.size(); int count = 0;
    k = k % N;  // rotate k items at tail to front
    // k = (N - k) % N;    // rotate k items at front to tail

    for (int i=0; count < N; ++i) {
        int c=i; int prev = nums[i];
        do {
            int j=(c+k)%N;
            int temp = nums[j];

            nums[j] = prev;
            prev = temp;

            c = j;
            ++count;
        } while (i != c);
    }
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  int k_steps = 2;
  myPrint(nums); // before
  rotate(nums, k_steps);
  myPrint(nums); // after
  return 0;
}
