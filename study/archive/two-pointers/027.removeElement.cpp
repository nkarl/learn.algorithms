#include "../utils.cpp"

/*
 * Remove all elements that match the given value.
 */

int removeElement(vector<int> &nums, int val) {
    int k= 0;
    for (int l=0, i=0; i < nums.size(); ++i) {
        //printf("for i=%d; l=%d\n", i, l);
        //printf("nums[%d]==%d; nums[%d]==%d", i, nums[i], l, nums[l]);
        if (nums[i] != val) {
            //printf("\tswapping\n");
            //swap(nums[l], nums[i]);
            nums[l]= nums[i];
            //printf("\t\t");
            //myPrint(nums);
            ++l;
        }
        else {
            //printf("\n\t\t");
            //myPrint(nums);
        }
        //printf("\n");
        k= l;
    }
    return nums.size() - (nums.size() - k);
}

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
    vector<int> nums= {1, 0, 2, 0, 3};
    int         val = 3;
    myPrint(nums);  // before
    int c= removeElement(nums, val);
    myPrint(nums);  // after
    for (int i= 0; i < c; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
