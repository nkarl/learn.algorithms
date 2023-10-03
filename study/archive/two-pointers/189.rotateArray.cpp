#include "../utils.cpp"

/*
 * Rotates k elements at the tail to the front of an array.
 *  Input:
 *      [1,2,3,4,5,6,7]
 *      k = 3
 *  Output:
 *      [5,6,7,1,2,3,4]
 *
 *  Description:
 *      New solution is simpler and makes more sense.
 *      The idea is that we break the problem into smaller pieces and solve each.
 *      After that we assemble the pieces (already solved) and give the final inductive solution.
 *      This is because we have a regular pattern, where the array is in order. That means
 *      every piece is sorted under the same ordering principle. When we assemble the sorted
 *      pieces and apply the pattern, the final solution is also sorted under the same ordering
 *      principle.
 *
 *  Complexity:
 *      O(N) time
 *      O(1) space
 */

void reverse(vector<int> &nums, int start, int end) {
    int temp = 0;
    while (start < end) {
        temp        = nums[start];
        nums[start] = nums[end];
        nums[end]   = temp;
        start++;
        end--;
        myPrint(nums);
    }
}

void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    reverse(nums, 0, nums.size() - k - 1);
    reverse(nums, nums.size() - k, nums.size() - 1);
    reverse(nums, 0, nums.size() - 1);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<int> nums    = {1, 2, 3, 4, 5, 6};
    int         k_steps = 2;
    myPrint(nums);  // before
    rotate(nums, k_steps);
    myPrint(nums);  // after
    return 0;
}
