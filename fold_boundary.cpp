// Example:
// Suppose to calculate hash value for Key = 123456789 and size of required
// address is 3 digits, we need to follow below steps:
// Step 1: The Key will be divided into two parts
// Key = 123 | 456 | 789
// Step 2:Reverse left and right parts and add it with middle part.
// 321 (folding applied)+456+987 (folding applied) = 1764(discard 1
// or 4)
// After we ignore the carry 1 (because here only three digits are
// required as hash value) the resulting hash value for 123456789 is 764.
// Algorithm:
// Step 1: Specify the number which is to be folded and boundary between
// them.
// fold_boundary(int key, int size)
// Step 2: Initialize all the integer values.
// Set: key_sum=0, key_frac=0, middle=0, left=0, right=0, digits=0,
// key_length=0
// Set: key_roll=key & fraction = size
// Step 3: Calculate key_length
// count_digits(key)
// a. Initialize count with value zero
// b. Repeat while (key!=0)
// Key/=10;
// ++count
// [End while]
// c. Return count
// d. Terminate function
// Step 4: Divide the number in three parts around a fixed boundary on left
// and right side.
// Step 5: Compute first three digits of given number. Reverse it and store
// the reversed value in left variable.
// Step 6: Compute last three digits of the given number. Reverse it and store
// the reversed value in right variable.
// Step 7: Find middle value of the given number and store it in variable
// middle.
// Step 8: Calculate key_sum
// key_sum = left + middle + right
// Step 9: If carry is generated then ignore carry
// Set: key_sum= key_sum % (int)pow(10, (fraction))
// Step 10: Print: key_sum
// Step 11: End

#include <stdio.h>
#include <string.h>
#include <math.h>
int count_digits(int key)
{
    int count = 0;
    while (key != 0)
    {
        key /= 10;
        ++count;
    }
    return count;
}
int reversDigits(int num)
{
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
int fold_boundary(int key, int size)
{
    int key_roll = key;
    int key_sum = 0;
    int key_frac = 0;
    int middle = 0;
    int left = 0;
    int right = 0;
    int digits = 0;
    int key_length = 0;
    int fraction = size;
    key_length = count_digits(key_roll);
    key_frac = key_roll / (int)pow(10, (key_length - fraction)); // start digit
    left = reversDigits(key_frac);
    key_roll = key_roll % (int)pow(10, 3);
    right = reversDigits(key_roll);
    digits = (int)log10(key) + 1;
    middle = (int)(key / pow(10, digits / 2)) % 10;
    key_sum = left + middle + right;
    return key_sum % (int)pow(10, (fraction)); // ignore carry
}
int main()
{
    printf("\n%d", fold_boundary(3347878, 3)); // 318
    printf("\n%d\n", fold_boundary(1234678, 3)); // 201
    return 0;
}