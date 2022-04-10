// Example:
// Suppose to calculate hash value for X = 5678 and hash table size 100, we
// need to follow below steps:
// Step 1: The X will be divided into two parts each having two digits i.e.
// k1=56 and k2 = 78
// Step 2: Adding all key parts
// k1 + k2 i.e.
// Key= 56 + 78 = 134
// After ignoring the carry 1 (because here only two digits are
// required as hash value) the resulting hash value for 5678 is 34.
// Algorithm:
// Step 1:The folding method is used for creating hash functions starts with
// the item being divided into equal-sized pieces i.e., the last piece may not
// be of equal size.
// Step 2:The outcome of adding these bits together is the hash value, H(x) =
// (a + b + c) mod M, where a, b, and c represent the preconditioned key
// broken down into three parts and M is the table size, and mod stands for
// modulo.
// Step 3:In other words, the sum of three parts of the preconditioned key is
// divided by the table size. The remainder is the hash key.

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
int fold_shift(int key, int size)
{
    int key_roll = key;
    int key_sum = 0;
    int key_frac = 0;
    int key_length = 0;
    int fraction = size;
    key_length = count_digits(key_roll);
    while (key_length > 0)
    {
        if (key_length > fraction)
        {
            key_frac = key_roll / (int)pow(10, (key_length - fraction));
            key_sum += key_frac;
            key_roll = key_roll % (int)pow(10, (key_length - fraction));
            key_length = key_length - fraction;
        }
        else
        {
            key_sum += key_roll;
            break;
        }
    }
    return key_sum % (int)pow(10, (fraction));
}
int main()
{

    printf("\n%d", fold_shift(12789, 3));    // 216
    printf("\n%d", fold_shift(12345678, 1)); // 6
    printf("\n%d\n", fold_shift(5678, 2));     // 34
    return 0;
}