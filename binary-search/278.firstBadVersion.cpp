#include "../utils.hpp"

bool isBadVersion(int v) {
    return true;
}

int search(vector<int>& nums, int target) {
    int head = 0, tail = nums.size() - 1;

    while (head <= tail) {
      int mid = head + (tail - head) / 2;

      if (isBadVersion(mid)) tail = mid - 1;
      else                   head = mid + 1;
    }

    return head;
}

int main(int argc, char* argv[]) {

    vector<int> nums = { -1, 0, 2, 5, 9, 11 };
    //vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int key = 5;

    myPrint(nums); // before

    int res = search(nums, key);
    cout << "key index:" << res << endl;
    //cout << endl;
    //cout << typeid(nums).name() << endl;

    myPrint(nums); // after
    return 0;
}
