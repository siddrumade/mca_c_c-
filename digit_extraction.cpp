#include <stdio.h>
int digit_extraction(int key)
{
    int key_length = 0;
    int first_digit = 0;
    int fourth_digit = 0;
    first_digit = key % 10000000;
    first_digit = first_digit / 1000000;
    fourth_digit = key % 1000;
    fourth_digit = fourth_digit / 100;
    printf("%d key would be hashed at location %d%d\n",key,first_digit, fourth_digit);
    return 0;
}
int main()
{
    digit_extraction(1347878); // 18
    digit_extraction(1234678); // 16
    return 0;
}

// Algorithm:
// Step 1: Begin
// Step 2: Pass key value ‘Key’ as an argument to digit_extraction().
// Step 3: Initialize values
// Set: first_digit=0 and fouth_digit=0 //for extracting digit at first &
// fourth position
// Step 4: For extracting first digit from given no
// Calculate: first_digit= key%10000000;
// first_digit=first_digit/1000000;
// Step 5: For extracting fourth digit from given no
// Calculate: fourth_digit= key%1000;
// fourth_digit=fourth_digit/100;
// Step 6: Display the hashed location where given number will be stored.
// Print: (first_digit, fourth_digit);
// Step 7:End
