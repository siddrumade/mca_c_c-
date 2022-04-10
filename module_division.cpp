#include <stdio.h>

#define size 7
int arr[size];
void init()
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}
void insert(int value)
{
    int key = value % size; // use of modulo division
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision : arr[%d] has element %d already!\n", key, arr[key]);
        printf("Unable to insert %d\n", value);
    }
}
void search(int value)
{
    int key = value % size;
    if (arr[key] == value)
    {
        printf("Search Found\n");
    }
    else
    {
        printf("Search Not Found\n");
    }
}
void display()
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}
int main()
{
    init();
    insert(10); // key = 10 % 7 ==> 3
    insert(4);  // key = 4 % 7 ==> 4
    insert(2);  // key = 2 % 7 ==> 2
    insert(3);  // key = 3 % 7 ==> 3 (collision)
    printf("Hash table\n");
    display();
    printf("\n");
    printf("Searching value 4..\n");
    search(4);

    return 0;
}

// Algorithm:
// Suppose array name is A and n is the size of array.
// Step 1: Initialize all array values with -1.
// Step 2: Specify the values which needs to be inserted.
// Step 3: Calculate key address using modulo division method.
// Set key= value % size
// Step 4: 
// If A[key] = = -1
//     Set A[key] = value // Insert the value at calculated key or address
// Else
//     Print: Unable to insert
// [End If]
// Step 5: 
// If A[key] = = value
//     Print: Search found
// Else
//     Print: Search not found
// [End If]
// Step 6: Repeat while key< n
// Print: A[key]
// [End while]
// Step 7: End