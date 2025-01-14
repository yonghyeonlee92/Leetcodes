/*

Problem URL : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Example 1:
Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.

Example 2:
Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
 

Constraints:
• 1 <= A.length == B.length == n <= 50
• 1 <= A[i], B[i] <= n
• It is guaranteed that A and B are both a permutation of n integers.

*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int freq[50] = {0};

    int* answer = (int*)malloc(sizeof(int) * ASize);

    for (int i=0; i < ASize; i++) {
        freq[A[i] - 1]++;
        freq[B[i] - 1]++;

        int common = 0;
        for (int j=0; j < 50; j++) {
            if (freq[j] == 2) {
                common++;
            }
        }

        answer[i] = common;
    }

    *returnSize = ASize;
    return answer;
}

int main(void){
    int returnSize = 0;

    // Example 1
    int A[4] = {1,3,2,4}, B[4] = {3,1,2,4};
    int ASize = 4, BSize = 4;

    // Example 2
    // int A[3] = {2,3,1}, B[3] = {3,1,2};
    // int ASize = 3, BSize = 3;

    int* result = findThePrefixCommonArray(A, ASize, B, BSize, &returnSize);
    for (int i=0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
