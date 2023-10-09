#include "../utils.cpp"

/*
 * Remove all duplicates for all elements in a sorted array, by swapping the sorted non-dup to the front.
 */
int removeDuplicates(vector<int> &nums) {
    int k = 1;
    for (int i = 1; i < nums.size(); ++i) {
        // printf("for=%d; k=%d\n", c, k);
        // printf("nums[%d]==%d; nums[%d]==%d", c, nums[c], k, nums[k]);
        if (nums[i - 1] != nums[i]) {
            // printf("\tswapping\n");
            //swap(nums[k], nums[i]);
            nums[k] = nums[i];
            // printf("\t\t");
            // myPrint(nums);
            ++k;
        }
        else {
            // printf("\n\t\t");
            // myPrint(nums);
        }
        // printf("\n");
    }
    return k;
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int         val  = 3;
    myPrint(nums);  // before
    int c = removeDuplicates(nums);
    myPrint(nums);  // after
    for (int i = 0; i < c; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
