/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *re = (int*) malloc(sizeof(int)*2);
    re[0] = 0;
    re[1] = 1;

    for (int i = 0;  i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j ++) {
            if ((nums[i] + nums[j]) == target) {
                re[0] = i;
                re[1] = j;
                *returnSize = 2; 
            }
        }
    }
    return re;
}


// @lc code=end

