#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int compare_int(const void * a, const void * b) {
    if (*(int *)a == *(int *)b) {
        return 0;
    } else {
        return (*(int *)a < *(int *)b) ? -1 : 1;
    }
}

bool containsDuplicate(int * nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare_int);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}

int main(int argc, char ** args) {
    int nums[10] = {1,1,1,3,3,4,3,2,4,2};
    if (containsDuplicate(nums, 4)) {
        printf("Contains duplicate\n");
    } else {
        printf("No duplicate\n");
    }
}
