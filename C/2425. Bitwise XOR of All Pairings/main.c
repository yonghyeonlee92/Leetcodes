/*

Problem URL : https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/

You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.


Example 1:
Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
 

Constraints:
ㆍ 1 <= nums1.length, nums2.length <= 105
ㆍ 0 <= nums1[i], nums2[j] <= 109

*/

#include <stdio.h>

int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int answer = 0;
    int xor = 0;
    for (int i=0; i < nums1Size; i++) {
        xor ^= nums1[i];
    }

    // printf("%d", xor);

    if (nums1Size % 2 == 1) {
        for (int j=0; j < nums2Size; j++) {
            answer ^= xor ^ nums2[j];
        }
    }
    else {
        for (int k=0; k < nums2Size; k++) {
            answer ^= xor;
        }
    }

    return answer;
}

int main(void){
    // Example 1
    int nums1[3] = {2,1,3}, nums2[4] = {10,2,5,0};
    int nums1Size = 3, nums2Size = 4;

    // Example 2
    // int nums1[2] = {1,2}, nums2[2] = {3,4};
    // int nums1Size = 2, nums2Size = 2;


    int result = xorAllNums(nums1, nums1Size, nums2, nums2Size);
    printf("%d", result);

    return 0;

}
