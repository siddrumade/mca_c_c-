// Steps for collision resolution using linear probing are as follows.
// Step 1: Calculate the hash key.
// address = key % size;
// Step 2: If hashTable[key] is empty, store the value directly.
// hashTable[key] = data.
// If the hash index already has some value, check for next index.
// Next address = (key+1) % size;
// If the next index is available hashTable[key], store the value.
// Otherwise try for next index.
// h(k) = (key+i) % size; where i= 0,1,2,3,...
// Step 3:Do the above process till we find the space

// Algorithm:
// Consider x is original array of elements, n is total no of elements in x, and
// ht is hash table array.
// Step 1: Enter total no of elements to store and enter those elements.
// Accept: n and values of x[i]
// Step 2: Initialize empty hash table, Repeat while i < size
// Set ht[i]=-1 //empty hash table
// Step 3: Repeat while i< n
// Set key= x[i];
// Set address=modulodivision(key)
// If address not equals to -1
// Set address= linearprobe(address)
// else
// Set address=key
// [End If]
// [End while]
// Step 4: End
// modulodivision(key)
// Step 1: Calculate address as
// address= key%size+1
// Step 2: If address equal to size of hash table
// Set address=0
// Else
// Return address
// [End If]
// linearprobe(address)
// Step 1:Repeat while address in hash table is not empty
// Find next address
// If address == size //address equals to last address of hash
// table
// Set address = 0 //point address to first address in
// hash table
// [End If]
// [End while]
// Step 2: Return Address

#include <stdio.h>
#define size 10
int ht[size];
void store(int x[], int n);
int modulodivision(int key);
int linearprobe(int address);
int main()
{
    int i, n, x[10];
    char ch;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    store(x, n);
    printf("Hashtable is as shown:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", ht[i]);
    }
    return 0;
}
void store(int x[], int n)
{
    int i, key, address;
    /* Initializing hash table to empty */
    for (i = 0; i < size; i++)
        ht[i] = -1;
    /* Copying elements from original array to hashtable */
    for (i = 0; i < n; i++)
    {
        key = x[i];
        address = modulodivision(key);
        if (ht[address] != -1)
            address = linearprobe(address);
        ht[address] = key;
    }
}
/* Hash Function */
int modulodivision(int key)
{
    int address;
    address = key % size + 1;
    if (address == size)
    {
        return 0;
    }
    else
    {
        return address;
    }
}
/* Collision Resolution */
int linearprobe(int address)
{
    while (ht[address] != -1)
    {
        address++;
        if (address == size)
            address = 0;
    }
    return address;
}